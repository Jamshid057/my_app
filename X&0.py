def print_board(board):
    print()
    for row in board:
        print(" | ".join(row))
        print("-" * 5)
    print()


def check_winner(board, player):
    for row in board:
        if all(cell == player for cell in row):
            return True

    for col in range(3):
        if all(board[row][col] == player for row in range(3)):
            return True

    if all(board[i][i] == player for i in range(3)):
        return True
    if all(board[i][2 - i] == player for i in range(3)):
        return True

    return False


def is_full(board):
    return all(cell != " " for row in board for cell in row)


def play_game():
    board = [[" " for _ in range(3)] for _ in range(3)]
    current_player = "X"

    print("X va O o‘yini!")
    print_board(board)

    while True:
        try:
            row = int(input(f"{current_player} - qatorni kiriting (0-2): "))
            col = int(input(f"{current_player} - ustunni kiriting (0-2): "))
        except ValueError:
            print("Faqat son kiriting!")
            continue

        if row not in range(3) or col not in range(3):
            print("Xatolik: qator va ustun 0 dan 2 gacha bo‘lishi kerak!")
            continue

        if board[row][col] != " ":
            print("Bu joy allaqachon band!")
            continue

        board[row][col] = current_player
        print_board(board)

        if check_winner(board, current_player):
            print(f"{current_player} yutdi! Tabriklaymiz! 🎉")
            break

        if is_full(board):
            print("Durrang!")
            break

        current_player = "O" if current_player == "X" else "X"


play_game()

