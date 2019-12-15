
OPCHDAAutops.dll: dlldata.obj OPCHDAAuto_p.obj OPCHDAAuto_i.obj
	link /dll /out:OPCHDAAutops.dll /def:OPCHDAAutops.def /entry:DllMain dlldata.obj OPCHDAAuto_p.obj OPCHDAAuto_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del OPCHDAAutops.dll
	@del OPCHDAAutops.lib
	@del OPCHDAAutops.exp
	@del dlldata.obj
	@del OPCHDAAuto_p.obj
	@del OPCHDAAuto_i.obj
