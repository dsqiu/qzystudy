SOURCE = \
aboutdialog.c           expander.c             recentchooserwidget.c \
action.c		filechooserbutton.c    scale.c		     \
arrow.c			filechooserdialog.c    scalebutton.c	     \
aspectframe.c		filechooserwidget.c    scrollbar.c	     \
assistant.c		fixed.c		       scrolledwindow.c	     \
box.c			fontbutton.c	       separator.c	     \
button.c		fontselection.c	       sizegroup.c	     \
buttonbox.c		fontselectiondialog.c  socket.c		     \
calendar.c		frame.c		       spinbutton.c	     \
cellrenderercombo.c	handlebox.c	       spinner.c	     \
cellrendererspin.c	hsv.c		       statusbar.c	     \
cellrendererspinner.c	image.c		       statusicon.c	     \
cellrenderertext.c	infobar.c	       table.c		     \
checkbutton.c		layout.c	       textview.c	     \
clipboard.c		linkbutton.c	       toggleaction.c	     \
colorbutton.c		liststore.c	       togglebutton.c	     \
colorselection.c	messagedialog.c	       toolbar.c	     \
colorselectiondialog.c	notebook.c	       toolpalette.c	     \
combobox.c		pane.c		       tooltipadvanced.c     \
commonframe.c		plug.c		       tooltipbasic.c	     \
dialog.c		progressbar.c	       treestore.c	     \
entry.c			radiobutton.c	       volumebutton.c	     \
entrybuffer.c		recentchooserdialog.c  window.c		     \
entrycompletion.c       recentchoosermenu.c    

ALL_PROJS = $(basename $(SOURCE))

ALL_PROJS_CLEAN = $(foreach proj,$(ALL_PROJS),$(proj)-clean)

# create projects targets

# define a function which creates a target for each proj
define CREATE_PROJ_TARGET
$1:
	gcc `pkg-config --cflags gtk+-2.0` $1.c -o $1 `pkg-config --libs gtk+-2.0`
$1-clean: 
	rm $1
endef
################ TARGETS ##################

.PHONY: all $(ALL_PROJS) $(ALL_PROJS_CLEAN)

# additional dependencies
# clean is cleaning all projects

all:$(ALL_PROJS)


$(foreach proj,$(ALL_PROJS),$(eval $(call CREATE_PROJ_TARGET,$(proj))))

clean:$(ALL_PROJS_CLEAN)
