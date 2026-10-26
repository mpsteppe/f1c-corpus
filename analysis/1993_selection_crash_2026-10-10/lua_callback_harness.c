#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
typedef void L;
typedef int (__cdecl *CF)(L*);
int main(int argc,char**argv){
 HMODULE h=LoadLibraryA(argv[1]); if(!h){printf("load failed %lu\n",GetLastError());return 2;}
 L* (__cdecl *newstate)(void)=(void*)GetProcAddress(h,"luaL_newstate");
 void (__cdecl *requiref)(L*,const char*,CF,int)=(void*)GetProcAddress(h,"luaL_requiref");
 void (__cdecl *settop)(L*,int)=(void*)GetProcAddress(h,"lua_settop");
 int (__cdecl *loadfile)(L*,const char*,const char*)=(void*)GetProcAddress(h,"luaL_loadfilex");
 int (__cdecl *pcall)(L*,int,int,int,int,void*)=(void*)GetProcAddress(h,"lua_pcallk");
 const char* (__cdecl *tolstring)(L*,int,size_t*)=(void*)GetProcAddress(h,"lua_tolstring");
 void (__cdecl *closefn)(L*)=(void*)GetProcAddress(h,"lua_close");
 L*l=newstate(); const char*libs[]={"_G","string","io"};const char*fns[]={"luaopen_base","luaopen_string","luaopen_io"};
 for(int i=0;i<3;i++){requiref(l,libs[i],(CF)GetProcAddress(h,fns[i]),1);settop(l,0);}
 int rc=loadfile(l,argv[2],NULL);if(!rc)rc=pcall(l,0,0,0,0,NULL);
 if(rc)printf("ERROR %d: %s\n",rc,tolstring(l,-1,NULL));else printf("PASS\n");
 closefn(l);FreeLibrary(h);return rc;
}
