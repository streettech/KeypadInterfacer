import tkinter as tk
from tkinter import ttk

root = tk.Tk()
root.title("G Pad Associate")

# functions
def callback(args):
    print(f"{args}")

# set window dimensions
window_height = 400
window_width = 600

# get screen dimensions
screen_height = root.winfo_screenheight()
screen_width = root.winfo_screenwidth()

# set min and max window size
min_width = 600
min_height = 400
max_width = screen_width
max_height = screen_height

# get center of screen
center_x = int(screen_width/2 - window_width/2)
center_y = int(screen_height/2 - window_height/2)

# window attributes
root.geometry(f"{window_width}x{window_height}")
root.minsize(min_width, min_height)
root.maxsize(max_width, max_height)
root.attributes("-alpha", 0.8)
root.attributes("-topmost", 1)
root.iconbitmap("./img/graphitert_logo_black.ico")

# set widgets
# text widgets
label = ttk.Label(root)
label.config(text="Hello World!")
label.pack()
# button widgets
button = ttk.Button(root,
                    text="Button",
                    command=lambda: callback("Hello u!"))
button.pack()

root.mainloop()