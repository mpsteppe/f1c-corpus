// Function: __mbsnbicoll @ 00597f6d
// Size (bytes): 63


/* Library Function - Single Match
    __mbsnbicoll
   
   Library: Visual Studio 2003 Release */

int __cdecl __mbsnbicoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  int iVar1;
  
  if (_MaxCount == 0) {
    return 0;
  }
  iVar1 = FUN_0059807b(DAT_008d48e4,1,_Str1,_MaxCount,_Str2,_MaxCount,DAT_008d46bc);
  if (iVar1 == 0) {
    return 0x7fffffff;
  }
  return iVar1 + -2;
}


