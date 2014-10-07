#!/usr/bin/env python
# -*- coding: ISO-8859-1 -*-
#
# generated by wxGlade 11b82132ec86 on Sun Apr  7 09:46:05 2013
#

import wx

# begin wxGlade: dependencies
import gettext
# end wxGlade

# begin wxGlade: extracode
try:
    ID_EDIT = wx.ID_EDIT
except AttributeError:
    ID_EDIT = wx.NewId()
# end wxGlade


class TemplateInfoDialog(wx.Dialog):
    def __init__(self, *args, **kwds):
        # begin wxGlade: TemplateInfoDialog.__init__
        kwds["style"] = wx.DEFAULT_DIALOG_STYLE | wx.RESIZE_BORDER | wx.MAXIMIZE_BOX | wx.THICK_FRAME
        wx.Dialog.__init__(self, *args, **kwds)
        self.template_name = wx.TextCtrl(self, wx.ID_ANY, "")
        self.author = wx.TextCtrl(self, wx.ID_ANY, "")
        self.sizer_2_staticbox = wx.StaticBox(self, wx.ID_ANY, _("Author"))
        self.description = wx.TextCtrl(self, wx.ID_ANY, "", style=wx.TE_MULTILINE)
        self.sizer_3_staticbox = wx.StaticBox(self, wx.ID_ANY, _("Description"))
        self.instructions = wx.TextCtrl(self, wx.ID_ANY, "", style=wx.TE_MULTILINE)
        self.sizer_3_copy_staticbox = wx.StaticBox(self, wx.ID_ANY, _("Instructions"))
        self.button_1 = wx.Button(self, wx.ID_OK, "")
        self.button_2 = wx.Button(self, wx.ID_CANCEL, "")

        self.__set_properties()
        self.__do_layout()
        # end wxGlade

    def __set_properties(self):
        # begin wxGlade: TemplateInfoDialog.__set_properties
        self.SetTitle(_("wxGlade template information"))
        self.SetSize(wx.DLG_SZE(self, (250, 264)))
        self.template_name.SetFocus()
        # end wxGlade

    def __do_layout(self):
        # begin wxGlade: TemplateInfoDialog.__do_layout
        sizer_1 = wx.BoxSizer(wx.VERTICAL)
        sizer_4 = wx.BoxSizer(wx.HORIZONTAL)
        self.sizer_3_copy_staticbox.Lower()
        sizer_3_copy = wx.StaticBoxSizer(self.sizer_3_copy_staticbox, wx.HORIZONTAL)
        self.sizer_3_staticbox.Lower()
        sizer_3 = wx.StaticBoxSizer(self.sizer_3_staticbox, wx.HORIZONTAL)
        self.sizer_2_staticbox.Lower()
        sizer_2 = wx.StaticBoxSizer(self.sizer_2_staticbox, wx.HORIZONTAL)
        sizer_8 = wx.BoxSizer(wx.HORIZONTAL)
        template_name_copy = wx.StaticText(self, wx.ID_ANY, _("wxGlade template: "))
        template_name_copy.SetFont(wx.Font(-1, wx.DEFAULT, wx.NORMAL, wx.BOLD, 0, ""))
        sizer_8.Add(template_name_copy, 0, wx.ALL | wx.ALIGN_CENTER_VERTICAL, 10)
        sizer_8.Add(self.template_name, 1, wx.ALL | wx.ALIGN_CENTER_VERTICAL, 10)
        sizer_1.Add(sizer_8, 0, wx.EXPAND, 0)
        sizer_2.Add(self.author, 1, 0, 0)
        sizer_1.Add(sizer_2, 0, wx.ALL | wx.EXPAND, 5)
        sizer_3.Add(self.description, 1, wx.EXPAND, 0)
        sizer_1.Add(sizer_3, 1, wx.ALL | wx.EXPAND, 5)
        sizer_3_copy.Add(self.instructions, 1, wx.EXPAND, 0)
        sizer_1.Add(sizer_3_copy, 1, wx.ALL | wx.EXPAND, 5)
        sizer_4.Add(self.button_1, 0, 0, 0)
        sizer_4.Add(self.button_2, 0, wx.LEFT, 10)
        sizer_1.Add(sizer_4, 0, wx.ALL | wx.ALIGN_RIGHT, 10)
        self.SetSizer(sizer_1)
        self.Layout()
        self.Centre()
        # end wxGlade

# end of class TemplateInfoDialog

class TemplateListDialog(wx.Dialog):
    def __init__(self, *args, **kwds):
        # begin wxGlade: TemplateListDialog.__init__
        kwds["style"] = wx.DEFAULT_DIALOG_STYLE
        wx.Dialog.__init__(self, *args, **kwds)
        self.template_names = wx.ListBox(self, wx.ID_ANY, choices=[])
        self.sizer_7_staticbox = wx.StaticBox(self, wx.ID_ANY, _("Available templates"))
        self.template_name = wx.StaticText(self, wx.ID_ANY, _("wxGlade template:\n"))
        self.author = wx.TextCtrl(self, wx.ID_ANY, "", style=wx.TE_READONLY)
        self.sizer_2_copy_staticbox = wx.StaticBox(self, wx.ID_ANY, _("Author"))
        self.description = wx.TextCtrl(self, wx.ID_ANY, "", style=wx.TE_MULTILINE | wx.TE_READONLY)
        self.sizer_3_copy_1_staticbox = wx.StaticBox(self, wx.ID_ANY, _("Description"))
        self.instructions = wx.TextCtrl(self, wx.ID_ANY, "", style=wx.TE_MULTILINE | wx.TE_READONLY)
        self.sizer_3_copy_copy_staticbox = wx.StaticBox(self, wx.ID_ANY, _("Instructions"))
        self.btn_open = wx.Button(self, wx.ID_OPEN, "")
        self.btn_edit = wx.Button(self, ID_EDIT, _("&Edit"))
        self.btn_delete = wx.Button(self, wx.ID_DELETE, "")
        self.btn_cancel = wx.Button(self, wx.ID_CANCEL, "")

        self.__set_properties()
        self.__do_layout()

        self.Bind(wx.EVT_LISTBOX_DCLICK, self.on_open, self.template_names)
        self.Bind(wx.EVT_LISTBOX, self.on_select_template, self.template_names)
        self.Bind(wx.EVT_BUTTON, self.on_open, self.btn_open)
        self.Bind(wx.EVT_BUTTON, self.on_edit, id=ID_EDIT)
        self.Bind(wx.EVT_BUTTON, self.on_delete, self.btn_delete)
        # end wxGlade

    def __set_properties(self):
        # begin wxGlade: TemplateListDialog.__set_properties
        self.SetTitle(_("wxGlade template list"))
        self.SetSize(wx.DLG_SZE(self, (300, 200)))
        self.template_name.SetFont(wx.Font(-1, wx.DEFAULT, wx.NORMAL, wx.BOLD, 0, ""))
        # end wxGlade

    def __do_layout(self):
        # begin wxGlade: TemplateListDialog.__do_layout
        sizer_5 = wx.BoxSizer(wx.VERTICAL)
        sizer_4_copy = wx.BoxSizer(wx.HORIZONTAL)
        sizer_6 = wx.BoxSizer(wx.HORIZONTAL)
        sizer_1_copy = wx.BoxSizer(wx.VERTICAL)
        self.sizer_3_copy_copy_staticbox.Lower()
        sizer_3_copy_copy = wx.StaticBoxSizer(self.sizer_3_copy_copy_staticbox, wx.HORIZONTAL)
        self.sizer_3_copy_1_staticbox.Lower()
        sizer_3_copy_1 = wx.StaticBoxSizer(self.sizer_3_copy_1_staticbox, wx.HORIZONTAL)
        self.sizer_2_copy_staticbox.Lower()
        sizer_2_copy = wx.StaticBoxSizer(self.sizer_2_copy_staticbox, wx.HORIZONTAL)
        self.sizer_7_staticbox.Lower()
        sizer_7 = wx.StaticBoxSizer(self.sizer_7_staticbox, wx.VERTICAL)
        sizer_7.Add(self.template_names, 1, wx.ALL | wx.EXPAND, 3)
        sizer_6.Add(sizer_7, 1, wx.ALL | wx.EXPAND, 5)
        sizer_1_copy.Add(self.template_name, 0, wx.ALL | wx.ALIGN_CENTER_VERTICAL, 7)
        sizer_2_copy.Add(self.author, 1, 0, 0)
        sizer_1_copy.Add(sizer_2_copy, 0, wx.ALL | wx.EXPAND, 5)
        sizer_3_copy_1.Add(self.description, 1, wx.EXPAND, 0)
        sizer_1_copy.Add(sizer_3_copy_1, 1, wx.ALL | wx.EXPAND, 5)
        sizer_3_copy_copy.Add(self.instructions, 1, wx.EXPAND, 0)
        sizer_1_copy.Add(sizer_3_copy_copy, 1, wx.ALL | wx.EXPAND, 5)
        sizer_6.Add(sizer_1_copy, 2, wx.EXPAND, 0)
        sizer_5.Add(sizer_6, 1, wx.EXPAND, 0)
        sizer_4_copy.Add(self.btn_open, 0, 0, 0)
        sizer_4_copy.Add(self.btn_edit, 0, wx.LEFT, 10)
        sizer_4_copy.Add(self.btn_delete, 0, wx.LEFT, 10)
        sizer_4_copy.Add(self.btn_cancel, 0, wx.LEFT, 10)
        sizer_5.Add(sizer_4_copy, 0, wx.ALL | wx.ALIGN_RIGHT, 10)
        self.SetSizer(sizer_5)
        self.Layout()
        self.Centre()
        # end wxGlade

    def on_open(self, event):  # wxGlade: TemplateListDialog.<event_handler>
        print "Event handler 'on_open' not implemented!"
        event.Skip()

    def on_select_template(self, event):  # wxGlade: TemplateListDialog.<event_handler>
        print "Event handler 'on_select_template' not implemented!"
        event.Skip()

    def on_edit(self, event):  # wxGlade: TemplateListDialog.<event_handler>
        print "Event handler 'on_edit' not implemented!"
        event.Skip()

    def on_delete(self, event):  # wxGlade: TemplateListDialog.<event_handler>
        print "Event handler 'on_delete' not implemented!"
        event.Skip()

# end of class TemplateListDialog
if __name__ == "__main__":
    gettext.install("app") # replace with the appropriate catalog name

    app = wx.PySimpleApp(0)
    wx.InitAllImageHandlers()
    template_info_dialog = TemplateInfoDialog(None, wx.ID_ANY, "")
    app.SetTopWindow(template_info_dialog)
    template_info_dialog.Show()
    app.MainLoop()
