
//Dhruva Sogal 10/18/18
import java.awt.BorderLayout; //assorted imports
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class GUITTT implements ActionListener {  //initial states of all variables, strings etc.
	JFrame frame = new JFrame();
	JButton[][] button = new JButton[3][3];
	int[][] board = new int[3][3];
	final int BLANK = 0; // from ttt
	final int X_MOVE = 1;// from ttt
	final int O_MOVE = 2;// from ttt
	final int X_TURN = 0;// from ttt
	final int O_TURN = 1;// from ttt
	int turn = X_TURN;
	Container center = new Container();
	JLabel xLabel = new JLabel("X Wins:0");
	JLabel oLabel = new JLabel("O Wins:0");
	JButton xChangeName = new JButton("Change X's Name");
	JButton oChangeName = new JButton("Change O's Name");
	JTextField xChangeField = new JTextField(); // input from user
	JTextField oChangeField = new JTextField(); // input from user
	Container north = new Container();
	String xPlayerName = "X";
	String oPlayerName = "O";
	int xWins = 0;
	int oWins = 0;
	int tieCount = 0;

	public GUITTT() {                                 //adds stuff to the grid
		frame.setSize(400, 400);
		// center container
		frame.setLayout(new BorderLayout());
		center.setLayout(new GridLayout(3, 3));
		for (int i = 0; i < button.length; i++) {
			for (int j = 0; j < button[0].length; j++) {
			button[j][i] = new JButton(""); 
				center.add(button[j][i]);
				button[j][i].addActionListener(this);
			}
		}

		frame.add(center, BorderLayout.CENTER);
		// north layout
		north.setLayout(new GridLayout(3, 2));   //layout of the grid including buttons
		north.add(xLabel);
		north.add(oLabel);
		north.add(xChangeName);
		north.add(oChangeName);
		north.add(xChangeField);
		north.add(oChangeField);
		xChangeName.addActionListener(this);
		oChangeName.addActionListener(this);
		frame.add(north, BorderLayout.NORTH);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		frame.setVisible(true);

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new GUITTT();
	}

	@Override
	public void actionPerformed(ActionEvent event) {
		JButton current;
		boolean gridButton = false;
		for (int i = 0; i < button.length; i++) { // checks which space is clicked
			for (int j = 0; j < button[0].length; j++) {
				if (event.getSource().equals(button[j][i])) {
					gridButton = true;
					current = button[j][i];
					if (board[j][i] == BLANK) {
						if (turn == X_TURN) { // adds x on x turn and disables
							current.setText("x");
							current.setEnabled(false);
							board[j][i] = X_MOVE;
							turn = O_TURN;
						} else if (turn == O_TURN) { // adds o on o turn and disables
							current.setText("o");
							board[j][i] = O_MOVE;
							turn = X_TURN;
							current.setEnabled(false);
						}
						// check for wins ties
						if (checkWin(X_MOVE) == true) {
							// X Wins
							xWins++;
							xLabel.setText(xPlayerName + "Wins:" + xWins); // updates score
							clearBoard(); 
							reEnable(); // reset
						} else if (checkWin(O_MOVE) == true) {
							// O Wins
							oWins++;
							oLabel.setText(oPlayerName + "Wins:" + oWins); // updates score
							clearBoard(); // reset
							reEnable();
						} else if (checkTie() == true) {
							// tie
							clearBoard(); // reset
							reEnable();
						}
					}
				}

			}
			if (gridButton == false) { // change name feature
				if (event.getSource().equals(xChangeName) == true) {

					xPlayerName = xChangeField.getText();
					if (xPlayerName.trim().length() > 0) { // length of trim is length on non-spaces, so no spaces
															// or blanks
						xLabel.setText(xPlayerName + "Wins:" + xWins);
					}

				} else if (event.getSource().equals(oChangeName) == true) { // change name feature
					oPlayerName = oChangeField.getText();
					if (oPlayerName.trim().length() > 0) { // length of trim is length on non-spaces, so no spaces
															// or blanks
						oLabel.setText(oPlayerName + "Wins:" + oWins);
					}

				}
			}

			// TODO Auto-generated method stub

		}

	}

	public boolean checkWin(int player) {          //checks for a win
		if (board[0][0] == player && board[0][1] == player && board[0][2] == player) { // top horizontal
			return true;
		}
		if (board[0][0] == player && board[1][1] == player && board[2][2] == player) { // left to right diagonal
			return true;
		}
		if (board[0][0] == player && board[1][0] == player && board[2][0] == player) { // left vertical
			return true;
		}
		if (board[0][1] == player && board[1][1] == player && board[2][1] == player) { // middle horizontal
			return true;
		}
		if (board[0][2] == player && board[1][2] == player && board[2][2] == player) { // bottom horizontal
			return true;
		}
		if (board[1][0] == player && board[1][1] == player && board[1][2] == player) { // middle vertical
			return true;
		}
		if (board[2][0] == player && board[2][1] == player && board[2][2] == player) { // right vertical
			return true;
		}
		if (board[2][0] == player && board[1][1] == player && board[0][2] == player) { // right to left diagonal
			return true;
		}

		return false;
	}

	public boolean checkTie() {          //checks for ties
		for (int row = 0; row < board.length; row++) {
			for (int column = 0; column < board[0].length; column++) {
				if (board[row][column] == BLANK) {
					return false;
				}

			}

		}
		return true;

	}

	public void clearBoard() {                          //makes the buttons blank
		for (int a = 0; a < board.length; a++) {
			for (int b = 0; b < board[0].length; b++) {
				board[a][b] = BLANK;
				button[a][b].setText("");

			}

		}
		turn = X_TURN;
	}

	public void reEnable() {                             //allows buttons to be clicked again
		for (int a = 0; a < board.length; a++) {
			for (int b = 0; b < board[0].length; b++) {
				button[a][b].setEnabled(true);
				
			}
			
		}

	}
}
// done with videos need to finish ties and re-enabling buttons
