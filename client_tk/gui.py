import threading
from tkinter import *
from tkinter import font
from tkinter import ttk
from cli import cli
# GUI class for the chat
class gui:
    # constructor method
    def __init__(self):
       
        self.cli = cli()
        # chat window which is currently hidden
        self.Window = Tk()
        self.Window.withdraw()
         
        # login window
        self.login = Toplevel()
        # set the title
        self.login.title("Login")
        self.login.resizable(width = False,
                             height = False)
        self.login.configure(width = 400,
                             height = 300)
        # create a Label
        self.pls = Label(self.login,
                       text = "Please login to continue",
                       justify = CENTER,
                       font = "Helvetica 14 bold")
         
        self.pls.place(relheight = 0.15,
                       relx = 0.2,
                       rely = 0.07)
        # create a Label
        self.labelName = Label(self.login,
                               text = "Name: ",
                               font = "Helvetica 12")
         
        self.labelName.place(relheight = 0.2,
                             relx = 0.1,
                             rely = 0.2)
         
        # create a entry box for
        # tyoing the message
        self.entryName = Entry(self.login,
                             font = "Helvetica 14")
         
        self.entryName.place(relwidth = 0.4,
                             relheight = 0.12,
                             relx = 0.35,
                             rely = 0.2)
                             
        self.labelHost = Label(self.login,
                               text = "Host: ",
                               font = "Helvetica 12")
         
        self.labelHost.place(relheight = 0.2,
                             relx = 0.1,
                             rely = 0.35)
         
        # create a entry box for
        # tyoing the message
        self.entryHost = Entry(self.login,
                             font = "Helvetica 14")
         
        self.entryHost.place(relwidth = 0.4,
                             relheight = 0.12,
                             relx = 0.35,
                             rely = 0.35)
         
        # set the focus of the cursor
        self.entryName.focus()
         
        # create a Continue Button
        # along with action
        self.go = Button(self.login,
                         text = "CONTINUE",
                         font = "Helvetica 14 bold",
                         command = lambda: self.goAhead(self.entryName.get(), self.entryHost.get()))
         
        self.go.place(relx = 0.4,
                      rely = 0.55)
        self.Window.bind('<Return>', self.returnHandler)
        self.Window.mainloop()
    def goAhead(self, name, host):
        self.login.destroy()
        self.layout(name)
        
        self.cli.initialize(name, host)
        self.name = name
        # the thread to receive messages
        rcv = threading.Thread(target=self.receive)
        rcv.start()
 
    def layout(self,name):
       
        self.name = name
        # to show chat window
        self.Window.deiconify()
        self.Window.title("CHATROOM")
        self.Window.resizable(width = False,
                              height = False)
        self.Window.configure(width = 470,
                              height = 550,
                              bg = "#17202A")
        self.labelHead = Label(self.Window,
                             bg = "#17202A",
                              fg = "#EAECEE",
                              text = self.name ,
                               font = "Helvetica 13 bold",
                               pady = 5)
         
        self.labelHead.place(relwidth = 1)
        self.line = Label(self.Window,
                          width = 450,
                          bg = "#ABB2B9")
         
        self.line.place(relwidth = 1,
                        rely = 0.07,
                        relheight = 0.012)
         
        self.textCons = Text(self.Window,
                             width = 20,
                             height = 2,
                             bg = "#17202A",
                             fg = "#EAECEE",
                             font = "Helvetica 14",
                             padx = 5,
                             pady = 5)
         
        self.textCons.place(relheight = 0.745,
                            relwidth = 1,
                            rely = 0.08)
         
        self.labelBottom = Label(self.Window,
                                 bg = "#ABB2B9",
                                 height = 80)
         
        self.labelBottom.place(relwidth = 1,
                               rely = 0.825)
         
        self.entryMsg = Entry(self.labelBottom,
                              bg = "#2C3E50",
                              fg = "#EAECEE",
                              font = "Helvetica 13")
         
        # place the given widget
        # into the gui window
        self.entryMsg.place(relwidth = 0.74,
                            relheight = 0.06,
                            rely = 0.008,
                            relx = 0.011)
         
        self.entryMsg.focus()
         
        # create a Send Button
        self.buttonMsg = Button(self.labelBottom,
                                text = "Send",
                                font = "Helvetica 10 bold",
                                width = 20,
                                bg = "#ABB2B9",
                                command = lambda : self.sendButton())
         
        self.buttonMsg.place(relx = 0.77,
                             rely = 0.008,
                             relheight = 0.06,
                             relwidth = 0.22)
         
        self.textCons.config(cursor = "arrow")
         
        # create a scroll bar
        scrollbar = Scrollbar(self.textCons)
         
        # place the scroll bar
        # into the gui window
        scrollbar.place(relheight = 1,
                        relx = 0.974)
         
        scrollbar.config(command = self.textCons.yview)
         
        self.textCons.config(state = DISABLED)
 
    def addMessage(self, name, message):
        self.textCons.config(state = NORMAL)
        self.textCons.insert(END, name+"\n"+message+"\n\n")
        self.textCons.config(state = DISABLED)
        self.textCons.see(END)
 
    # function to basically start the thread for sending messages
    def sendButton(self):
        self.textCons.config(state = DISABLED)
        self.msg=self.entryMsg.get()
        self.entryMsg.delete(0, END)
        snd= threading.Thread(target = self.sendMessage)
        self.addMessage(self.name, self.msg) 
        snd.start()
 
    # function to receive messages
    def receive(self):
        while True:
                try:
                # insert messages to text box
                    messages = self.cli.poll()
                    for message in messages:
                        self.addMessage(message[0], message[1])
                except:
                # an error will be printed on the command line or console if there's an error
                    print("An error occured!")
                    break
         
    # function to send messages
    def sendMessage(self):
        self.textCons.config(state=DISABLED)
        while True:
            try:
                self.cli.send(self.msg)
                break
            except:
                print("AN ERROR OCCURED!")
    def returnHandler(self, event):
        self.sendButton()
# create a GUI class object
g = gui()
