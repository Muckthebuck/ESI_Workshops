#define BOARD_WIDTH 3
#define BOARD_LENGTH pow(BOARD_WIDTH,2)

int board[9];

const char blank_tile = '*';
const char user_tile = 'X';
const char comp_tile = 'O';

const int blank_id = 0;
const int user_id = 1;
const int comp_id = 2;

const int win = 8;
const int loose = 7;
const int game = 12;
int player_move_text;

bool valid_move;
bool game_on = true;

// Array for board
// 0 1 2
// 3 4 5
// 6 7 8

void setup() {
	Serial.begin(9600);
  pinMode(win,OUTPUT);
  pinMode(loose,OUTPUT);
  pinMode(game,OUTPUT);
  digitalWrite(game,HIGH);
	startGame();

}

void loop() {

	if (game_on) {
    
		if (Serial.available()&(remainingTurns()>0)) {
			player_move_text = Serial.parseInt() - 1;
			Serial.println(player_move_text);
			if ((remainingTurns() % 2) == (user_id % 2)) {

				valid_move = turn(user_id, player_move_text);
				if (!valid_move) {
					Serial.println("invalid move...");
					printBoard();
				}
			}
			checkWinner(user_id);
		}

		if (((remainingTurns() % 2) == (comp_id % 2)&(remainingTurns()>0))) {
			valid_move = false;
			while (!valid_move) {
				valid_move = turn(comp_id, random(BOARD_LENGTH));
			}
			printBoard();
			checkWinner(comp_id);

		}
		if ((remainingTurns() == 0) & (game_on)) {
			Serial.println("It was a tie!?!?!");
		}
	}
	else {
    digitalWrite(game,LOW);
    digitalWrite(win,LOW);
    digitalWrite(loose,LOW);
    delay(100);
		startGame();
		game_on = true;
	}
	delay(100);
}


void printBoard() {
	Serial.println();
	for (int i = 0; i < BOARD_LENGTH; i++) {
		Serial.print((board[i] == 0) ? blank_tile : (board[i] == 1) ? user_tile : (board[i] == 2) ? comp_tile : '?');
		Serial.print(" ");
		if ((i % BOARD_WIDTH) == (BOARD_WIDTH - 1)) {
			Serial.print("\n");
		}
	}
	Serial.println();
}

void clearBoard() {
	for (int i = 0; i < BOARD_LENGTH; i++) {
		board[i] = 0;
	}
}

bool checkWinner(int player_id) {
	//for every for any row , col or diagonal and the value is eqaual to player_id
	bool is_winner = false;
	// Array for board
	// 0 1 2
	// 3 4 5
	// 6 7 8
	//Rows
	is_winner |= (player_id == board[0]) & (board[0] == board[1]) & (board[1] == board[2]);
	is_winner |= (player_id == board[3]) & (board[3] == board[4]) & (board[4] == board[5]);
	is_winner |= (player_id == board[6]) & (board[6] == board[7]) & (board[7] == board[8]);
	//Cols
	is_winner |= (player_id == board[0]) & (board[0] == board[3]) & (board[3] == board[6]);
	is_winner |= (player_id == board[1]) & (board[1] == board[4]) & (board[4] == board[7]);
	is_winner |= (player_id == board[2]) & (board[2] == board[5]) & (board[5] == board[8]);
	//Diag
	is_winner |= (player_id == board[0]) & (board[0] == board[4]) & (board[4] == board[8]);
	is_winner |= (player_id == board[2]) & (board[2] == board[4]) & (board[4] == board[6]);

	if (is_winner) {
		if (player_id == user_id) {
			Serial.println("YOU WIN!!!!!!!!!!!!!!!!!!!!!!!");
      digitalWrite(win,is_winner);  
      delay(1000);
		}
		else {
			Serial.println("YOU LOSE..............");
     digitalWrite(loose,is_winner); 
     delay(1000);
		}
		game_on = false;
	}
	return is_winner;
}

int remainingTurns() {
	int turns_rem = 0;
	for (int i = 0; i < BOARD_LENGTH; i++) {
		turns_rem += (board[i] == 0);
	}
	return turns_rem;
}

bool turn(int player_id, int player_move) {
	bool is_valid_turn = false;
	if ( (player_move >= 0) & (player_move < BOARD_LENGTH)) {
		if (board[player_move] == blank_id) {
			is_valid_turn = true;
			board[player_move] = player_id;
		}
	}
	return is_valid_turn;
}

void startGame() {
	clearBoard();
	Serial.println("-------------------------");
  digitalWrite(game,HIGH);
	Serial.println("TicTacToe Game starting...");
	Serial.print("You will be playing as ");
	Serial.print(user_tile);
	Serial.println(" against the Arduino!\nInput a number to make your move.");
	Serial.println("1 2 3\n4 5 6\n7 8 9");
	printBoard();
} 
