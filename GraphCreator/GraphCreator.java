//Dhruva Sogal Graph Creator and Traveling Salesman solver
//Completed 5/17/19

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.Arrays;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class GraphCreator implements ActionListener, MouseListener {

	JFrame frame = new JFrame();
	GraphPanel panel = new GraphPanel();
	JButton nodeB = new JButton("Node");
	JButton edgeB = new JButton("Edge");
	JTextField labelsTF = new JTextField("A");
	JTextField firstNode = new JTextField("First");
	JTextField secondNode = new JTextField("Second");
	JButton connectedB = new JButton("Test Connection");

	Container west = new Container();
	Container east = new Container();
	Container south = new Container();
	JTextField salesmanStartTF = new JTextField("A");
	JButton salesmanB = new JButton("Shortest Path");
	final int NODE_CREATE = 0;
	final int EDGE_FIRST = 1;
	final int EDGE_SECOND = 2;
	int state = NODE_CREATE;
	Node first = null;
	ArrayList<ArrayList<Node>> completed = new ArrayList<ArrayList<Node>>();
	ArrayList<Integer> totals = new ArrayList<>();
	int indexOfPath;
	int valueOfPath;
	int min;
	int minIdex;
	ArrayList<Node> pathReplace = new ArrayList<Node>();

	public GraphCreator() {
		frame.setSize(800, 600);
		frame.setLayout(new BorderLayout());
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.add(panel, BorderLayout.CENTER);
		west.setLayout(new GridLayout(3, 1));
		west.add(nodeB);
		nodeB.addActionListener(this);
		nodeB.setBackground(Color.GREEN);
		west.add(edgeB);
		edgeB.addActionListener(this);
		edgeB.setBackground(Color.LIGHT_GRAY);
		west.add(labelsTF);
		frame.add(west, BorderLayout.WEST);
		panel.addMouseListener(this);
		frame.add(east, BorderLayout.EAST);
		frame.setVisible(true);
		east.add(firstNode);
		east.add(secondNode);
		east.add(connectedB);
		connectedB.addActionListener(this);
		east.setLayout(new GridLayout(3, 1));
		south.setLayout(new GridLayout(1, 2));
		south.add(salesmanStartTF);
		south.add(salesmanB);
		salesmanB.addActionListener(this);
		frame.add(south, BorderLayout.SOUTH);

	}

	public static void main(String[] args) {
		new GraphCreator();

	}

	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mousePressed(MouseEvent e) {

	}

	@Override
	public void mouseReleased(MouseEvent e) {
		if (state == NODE_CREATE) {
			panel.addNode(e.getX(), e.getY(), labelsTF.getText());
		} else if (state == EDGE_FIRST) {
			// System.out.println("edge1");
			Node n = panel.getNode(e.getX(), e.getY());
			if (n != null) {
				first = n;
				state = EDGE_SECOND;
				n.setHighlighted(true);

			}

		} else if (state == EDGE_SECOND) {
			// System.out.println("edge2");
			Node n = panel.getNode(e.getX(), e.getY());
			if (n != null && !first.equals(n)) {
				String s = labelsTF.getText();
				boolean valid = true;
				for (int a = 0; a < s.length(); a++) {
					if (Character.isDigit(s.charAt(a)) == false) {
						valid = false;
					}

				}
				if (valid == true) {
					first.setHighlighted(false);
					panel.addEdge(first, n, labelsTF.getText());
					first = null;
					state = EDGE_FIRST;
				} else {
					JOptionPane.showMessageDialog(frame, "Can Only Have Digits in Edge Labels"); //invalid input
				}

			}

		}
		frame.repaint();

	}

	@Override
	public void mouseEntered(MouseEvent e) {

	}

	@Override
	public void mouseExited(MouseEvent e) {

	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource().equals(nodeB)) {
			// System.out.println("node");
			nodeB.setBackground(Color.GREEN);
			edgeB.setBackground(Color.LIGHT_GRAY);
			state = NODE_CREATE;

		}
		if (e.getSource().equals(edgeB)) {
			// System.out.println("edge");
			nodeB.setBackground(Color.LIGHT_GRAY);
			edgeB.setBackground(Color.GREEN);
			state = EDGE_FIRST;
			panel.stopHighlighting();
			frame.repaint();
		}
		if (e.getSource().equals(connectedB)) {       //checks if two nodes are connected
			if (panel.nodeExists(firstNode.getText()) == false) {
				JOptionPane.showMessageDialog(frame, "First Node is Not in Your Graph");       

			} else if (panel.nodeExists(secondNode.getText()) == false) {
				JOptionPane.showMessageDialog(frame, "Second Node is Not in Your Graph");

			} else {
				Queue queue = new Queue();
				ArrayList<String> connectedList = new ArrayList<String>();
				connectedList.add(panel.getNode(firstNode.getText()).getLabel());
				ArrayList<String> edges = panel.getConnectedLabels(firstNode.getText());
				for (int a = 0; a < edges.size(); a++) {
					// check each connected node
					queue.enqueue(edges.get(a));

				}
				while (queue.isEmpty() == false) {
					String currentNode = queue.dequeue();
					if (connectedList.contains(currentNode) == false) {
						connectedList.add(currentNode);
					}
					edges = panel.getConnectedLabels(currentNode);
					for (int a = 0; a < edges.size(); a++) {
						if (connectedList.contains((edges.get(a))) == false) {
							queue.enqueue(edges.get(a));

						}
					}

				}
				if (connectedList.contains(secondNode.getText())) {
					JOptionPane.showMessageDialog(frame, "Connected");

				} else {
					JOptionPane.showMessageDialog(frame, "Not Connected");
				}

			}
		}
		if (e.getSource().equals(salesmanB)) {
			if (panel.getNode(salesmanStartTF.getText()) != null) {
				 ArrayList<Node> nodes = new ArrayList<>();
				 nodes.add(panel.getNode(salesmanStartTF.getText()));
				
				
				travelling(panel.getNode(salesmanStartTF.getText()), nodes, 0);
				if (completed.size() > 0) {
					min=totals.get(0);
					for (int a = 0; a < totals.size(); a++) {
						if(totals.get(a)<min) { //finds the actual minimum path
							min=totals.get(a);
							minIdex=a;          //finds the min value
						}
						
						
						
					}
					System.out.println(min); //print out the minimum distance
					
					for (int i = 0; i < ((completed.get(minIdex)).size())/2; i++) {
						System.out.println((completed.get(minIdex)).get(i).getLabel());
//						System.out.println("hi");
						
					}

				} else {
					JOptionPane.showMessageDialog(frame, "There are No Paths");
				}
				
			} else {
				JOptionPane.showMessageDialog(frame, "Not a Valid Starting Node");
			}

		}

	}

	private void travelling(Node n, ArrayList<Node> path, int total) {
		// if the number of nodes in the path is equal to the the number of nodes
		if (panel.nodeList.size() == path.size()) {   //if contains all nodes
			completed.add(pathReplace);               // copies path as path is being modified 
			
			totals.add(total);                       //add totals to find the min    

			// remove the last thing in the path
			for (int a = 0; a < path.size(); a++) {
				pathReplace.add(path.get(a));
				
			}
			path.remove(path.size() - 1);
			//
			return;
		}

		else {
			for (int a = 0; a < panel.edgeList.size(); a++) {
				Edge e = panel.edgeList.get(a);
				if (e.getOtherEnd(n) != null) {
					if (path.contains(e.getOtherEnd(n)) == false) { //if it does not contain the other end
						path.add(e.getOtherEnd(n));
						travelling(e.getOtherEnd(n), path, total + Integer.parseInt(e.getLabel())); // total adds the
																									// value of edge
						

					}
				}

			}
			
			path.remove(path.size() - 1); // removes last object in the path
		}

		

	}

}
