#!/usr/bin/env python
#coding=utf-8

import pygtk
import gtk
import os
import sys

class BaseWindow:
  def delete_event(self, widget, data=None):
    print "delete_event"
 
  def destroy(self, widget, data=None):
    gtk.main_quit()

  def loginout(self, widget, data=None):
    os.system("fvwm -r")

  def shutdown(self, widget, data=None):
    os.system("shutdown -h now")

  def reboot(self, widget, data=None):
    os.system("shutdown -r now")
  
  def restart(self, widget, data=None):
    os.system("fvwm -r")
  def exit(self, widget, data=None):
    sys.exit()
    
  def __init__(self):
    print "关闭电脑"
    self.window = gtk.Window(gtk.WINDOW_POPUP)
    self.window.set_title("xyShutdown")
    self.window.set_position(gtk.WIN_POS_CENTER)
    self.window.set_modal(True)
    self.window.set_icon_name("gtk-quit")
    self.window.set_resizable(False)
    self.window.set_decorated(True)
    self.window.set_keep_above(True)
    self.window.connect("destroy", self.destroy)
    self.window.connect("delete_event", self.delete_event)

    self.boxv = gtk.VBox(False, 0)
    self.window.add(self.boxv)

    self.btnShutdown = xyImageButton("关闭电脑", "quit.xpm")
    self.btnShutdown.connect("clicked", self.shutdown, None)
    self.boxv.pack_start(self.btnShutdown, True, True, 0)
    
    self.btnReboot = xyImageButton("重启电脑", "restart.xpm")
    self.btnReboot.connect("clicked", self.reboot, None)
    self.boxv.pack_start(self.btnReboot, True, True, 0)
    
    self.btnRestart = xyImageButton("退出登录", "restart.xpm")
    self.btnRestart.connect("clicked", self.restart, None)
    self.boxv.pack_start(self.btnRestart, True, True, 0)


    self.btnCancel = xyImageButton("取消操作", "exit.xpm")
    self.btnCancel.connect("clicked", self.exit, None)
    self.boxv.pack_start(self.btnCancel, True, True, 0)

    self.btnCancel.show()
    self.btnRestart.show()
    self.btnReboot.show()
    self.btnShutdown.show()
    self.boxv.show()
    self.window.show() 

  def main(self):
    gtk.main()


class xyImageButton(gtk.Button):
  def __init__(self, text, image):
    gtk.Button.__init__(self)
    hbox = gtk.HBox(False, 0)
    img = gtk.Image()
    img.set_from_file(image)
    img.show()
    hbox.pack_start(img, True, True, 0)
    lbl = gtk.Label(text)
    lbl.show()
    hbox.pack_start(lbl, True, True, 0)
    hbox.show()   
    self.add(hbox)
   
baseWindow = BaseWindow()
baseWindow.main()
 
