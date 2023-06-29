# initializes the game board
board = [" " for i in range(9)]

# prints the current state of the game board
def print_board():
  row1 = "|".join(board[0:3])
  row2 = "|".join(board[3:6])
  row3 = "|".join(board[6:9])
  print()
  print(row1)
  print("-+-+-")
  print(row2)
  print("-+-+-")
  print(row3)
  print()

# determines if the game is over
def game_is_over():
  # check for a winner
  if (board[0] == board[1] == board[2] != " ") or \
     (board[3] == board[4] == board[5] != " ") or \
     (board[6] == board[7] == board[8] != " ") or \
     (board[0] == board[3] == board[6] != " ") or \
     (board[1] == board[4] == board[7] != " ") or \
     (board[2] == board[5] == board[8] != " ") or \
     (board[0] == board[4] == board[8] != " ") or \
     (board[2] == board[4] == board[6] != " "):
    return True

  # check for a draw
  if " " not in board:
    return True

  # game is not over
  return False

# loops until the game is over
while not game_is_over():
  # print the current state of the game board
  print_board()

  # get player input
  move = int(input("Enter your move (1-9): "))
  if board[move-1] == " ":
    board[move-1] = "X"
  else:
    print("That space is occupied! Please choose another.")
    continue

  # check for a winner or a draw
  if game_is_over():
    break

  # computer makes a move
  for i in range(9):
    if board[i] == " ":
      board[i] = "O"
      break

  # check for a winner or a draw
  if game_is_over():
    break

# print the final state of the game board
print_board()

# announce the winner
if "X" not in board:
  print("O wins!")
elif "O" not in board:
  print("X wins!")
else:
  print("It's a draw!")