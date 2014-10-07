# lisp_codegen.py : lisp generator functions for wxListBox objects
# $Id: lisp_codegen.py,v 1.1 2005/09/22 06:59:46 efuzzyone Exp $
#
# Copyright (c) 2002-2004 D.H. aka crazyinsomniac on sourceforge.net
# License: MIT (see license.txt)
# THIS PROGRAM COMES WITH NO WARRANTY


import common
from ChoicesCodeHandler import *


class LispCodeGenerator:
    def get_code(self, obj):
        codegen = common.code_writers['lisp']
        prop = obj.properties
        id_name, id = codegen.generate_code_id(obj)
        choices = prop.get('choices', [])
        if not obj.parent.is_toplevel:
            parent = '(slot-%s obj)' % obj.parent.name
        else:
            parent = '(slot-top-window obj)'

        style = prop.get("style")
        if not style:
            style = '0'
        else:
            style = codegen.cn_f(style)

        init = []
        if id_name: init.append(id_name)

        length = len(choices)
        choices = ' '.join([codegen.quote_str(c) for c in choices])
        init.append('(setf (slot-%s obj) (wxListBox_Create %s %s -1 -1 -1 -1 %s (vector %s) %s))\n'
                    % (obj.name, parent, id, length, choices, style))
        props_buf = codegen.generate_common_properties(obj)
        selection = prop.get('selection')
        if selection is not None:
            props_buf.append('(wxListBox_SetSelection (slot-%s obj) %s 1)\n' %
                             (obj.name, selection))
        return init, props_buf, []

# end of class LispCodeGenerator

def initialize():
    common.class_names['EditListBox'] = 'wxListBox'

    codegen = common.code_writers.get('lisp')
    if codegen:
        codegen.add_widget_handler('wxListBox', LispCodeGenerator())
        codegen.add_property_handler('choices', ChoicesCodeHandler)

