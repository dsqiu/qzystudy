#!/usr/bin/env python
import sys
import CppHeaderParser
import string
import os

def parameter(para):
    pstr = ""
    for p in para:
        if p["constant"]:
            pstr = pstr + "const "
        pstr = pstr + p["type"] + " "+ p["name"]
        if p["static"]:
            pstr = pstr + " = " + p["reference"]
    return pstr;
            
def main(hpp_name):
    sextname = os.path.splitext(hpp_name)
    extname = sextname[1]
    if not (cmp(extname,".hpp") or cmp(extname,".h")):
        sys.exit(1)
    base_name = os.path.basename(hpp_name)
    path_name = os.path.dirname(hpp_name)
    
    try:
        cppHeader = CppHeaderParser.CppHeader(hpp_name)
    except CppHeaderParser.CppParseError as e:
        print(e)
        sys.exit(1)
    cpp_name = sextname[0] + ".cpp"
    fp = open(cpp_name,"w")
    fp.write(str.format("#include <%s>\n" % base_name))
    for cls in cppHeader.classes:
        for p in cppHeader.classes[cls]["methods"]:
            for m in cppHeader.classes[cls]["methods"][p]:
                func_name = ""
                if m["destructor"]:
                    func_name = func_name + str.format("%s::~%s(" % (cls,m["name"]))
                    func_name = func_name + parameter(m["parameters"]) + ")\n"
                    func_name = func_name + "{\n"
                    func_name = func_name + "}\n"
                    fp.write(func_name)
                    continue
                elif m["constructor"]:
                    func_name = func_name + str.format("%s::%s(" % (cls,m["name"]))
                    func_name = func_name + parameter(m["parameters"]) + ")\n"
                    func_name = func_name + "{\n"
                    func_name = func_name + "}\n"
                    fp.write(func_name)
                    continue
                elif not m["pure_virtual"]:
                    if m["static"]:
                        func_name = func_name + "static "
                    func_name = func_name + str.format("%s %s::%s(" % (m["rtnType"],cls,m["name"]))
                    func_name = func_name + parameter(m["parameters"]) + ")\n"
                    func_name = func_name + "{\n"
                    if cmp(m["rtnType"],"void"):
                        if m["returns_pointer"]:
                            func_name = func_name + "return NULL;\n"
                        elif m["returns_class"]:
                            func_name = func_name + "return NULL;\n"
                        else:
                            func_name = func_name + "return 0;\n"
                    func_name = func_name + "}\n"
                    fp.write(func_name)
    fp.close();
    
if __name__ == '__main__':
    for fn in sys.argv[1::]:
        main(fn)
