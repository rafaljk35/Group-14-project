import numpy as np
import pygame
import sys
import math
import random

BLUE = (0,0,255)
BLACK = (0,0,0)
RED = (255,0,0)
YELLOW = (255,255,0)

#constants
ROW_COUNT = 6 #number of horizontal rows
COLUMN_COUNT = 7 #number of vertical columns
player = 0 #represents player
piece_player = 1 #represent token from player
ai = 1 #represents ai
piece_ai = 2 # represent token from ai


def create_board():
	board = np.zeros((ROW_COUNT,COLUMN_COUNT))
	return board

def drop_piece(board, row, col, piece):
	board[row][col] = piece

def is_valid_location(board, col):
	return board[ROW_COUNT-1][col] == 0

def get_next_open_row(board, col):
	for r in range(ROW_COUNT):
		if board[r][col] == 0:
			return r

def print_board(board):
	print(np.flip(board, 0))

def winning_move(board, piece):
	# Check horizontal locations for win
	for c in range(COLUMN_COUNT-3):
		for r in range(ROW_COUNT):
			if board[r][c] == piece and board[r][c+1] == piece and board[r][c+2] == piece and board[r][c+3] == piece:
				return True

	# Check vertical locations for win
	for c in range(COLUMN_COUNT):
		for r in range(ROW_COUNT-3):
			if board[r][c] == piece and board[r+1][c] == piece and board[r+2][c] == piece and board[r+3][c] == piece:
				return True

	# Check positively sloped diaganols
	for c in range(COLUMN_COUNT-3):
		for r in range(ROW_COUNT-3):
			if board[r][c] == piece and board[r+1][c+1] == piece and board[r+2][c+2] == piece and board[r+3][c+3] == piece:
				return True

	# Check negatively sloped diaganols
	for c in range(COLUMN_COUNT-3):
		for r in range(3, ROW_COUNT):
			if board[r][c] == piece and board[r-1][c+1] == piece and board[r-2][c+2] == piece and board[r-3][c+3] == piece:
				return True

def draw_board(board):
	for c in range(COLUMN_COUNT):
		for r in range(ROW_COUNT):
			pygame.draw.rect(screen, BLUE, (c*SQUARESIZE, r*SQUARESIZE+SQUARESIZE, SQUARESIZE, SQUARESIZE))
			pygame.draw.circle(screen, BLACK, (int(c*SQUARESIZE+SQUARESIZE/2), int(r*SQUARESIZE+SQUARESIZE+SQUARESIZE/2)), RADIUS)
	
	for c in range(COLUMN_COUNT):
		for r in range(ROW_COUNT):		
			if board[r][c] == piece_player:
				pygame.draw.circle(screen, RED, (int(c*SQUARESIZE+SQUARESIZE/2), height-int(r*SQUARESIZE+SQUARESIZE/2)), RADIUS)
			elif board[r][c] == piece_ai: 
				pygame.draw.circle(screen, YELLOW, (int(c*SQUARESIZE+SQUARESIZE/2), height-int(r*SQUARESIZE+SQUARESIZE/2)), RADIUS)
	pygame.display.update()

#func to look at entire board, count 2 and 3 in a rows
def score_position(board, piece): #piece identifies if player (1) or ai (2).
	#score horizontal
	e

board = create_board()
print_board(board)
game_over = False #flag for if game is over

pygame.init()

SQUARESIZE = 100

width = COLUMN_COUNT * SQUARESIZE
height = (ROW_COUNT+1) * SQUARESIZE

size = (width, height)

RADIUS = int(SQUARESIZE/2 - 5)

screen = pygame.display.set_mode(size)
draw_board(board)
pygame.display.update()

myfont = pygame.font.SysFont("monospace", 75)

turn = random.randint(player, ai) #randomly selects whos turn it is, can expand upon this later to allow manual selection

while not game_over:

	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			sys.exit()

		if event.type == pygame.MOUSEMOTION: 
			pygame.draw.rect(screen, BLACK, (0,0, width, SQUARESIZE))
			posx = event.pos[0]
			if turn == player: #if it's player's turn, draw red circle on top of board to represent token
				pygame.draw.circle(screen, RED, (posx, int(SQUARESIZE/2)), RADIUS)
		pygame.display.update()

		if event.type == pygame.MOUSEBUTTONDOWN: #when mouseclick detected
			pygame.draw.rect(screen, BLACK, (0,0, width, SQUARESIZE))
			#print(event.pos)
			# Ask for Player 1 Input
			if turn == player: # if it's the player's turn
				posx = event.pos[0]
				col = int(math.floor(posx/SQUARESIZE))

				if is_valid_location(board, col):
					row = get_next_open_row(board, col)
					drop_piece(board, row, col, piece_player) #drops player token

					if winning_move(board, piece_player):
						label = myfont.render("Player 1 wins!!", 1, RED)
						screen.blit(label, (40,10))
						game_over = True

                    #same for player, if location valid, change turn
					turn += 1
					turn = turn % 2

					#updates board after piece has been dropped
					print_board(board)
					draw_board(board)


    # # Ask for Player 2 Input
	if turn == ai and not game_over: #if it's the ai's turn and the game is not finished yet				
		col = random.randint(0, COLUMN_COUNT-1) #generates random number between 0 and number of columns

		if is_valid_location(board, col):
			pygame.time.wait(500) #waits a bit before dropping piece, remove if necessary
			row = get_next_open_row(board, col)
			drop_piece(board, row, col, piece_ai) #drops ai token

			if winning_move(board, piece_ai):
				label = myfont.render("Player 2 wins!!", 1, YELLOW)
				screen.blit(label, (40,10))
				game_over = True

			print_board(board)
			draw_board(board)

			#turn only changes when a valid location is chosen
			turn += 1
			turn = turn % 2

	if game_over:
		pygame.time.wait(3000)