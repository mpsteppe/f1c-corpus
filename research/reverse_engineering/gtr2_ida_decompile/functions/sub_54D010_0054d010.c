int __userpurge sub_54D010@<eax>(int a1@<ecx>, __int32 a2@<esi>, unsigned int a3)
{
  int v3; // eax
  unsigned int v4; // kr00_4
  int v5; // esi
  int result; // eax
  __int32 v7; // [esp+8h] [ebp-54h] BYREF
  char v8; // [esp+10h] [ebp-4Ch]
  int v9; // [esp+20h] [ebp-3Ch]
  int v10; // [esp+24h] [ebp-38h]

  if ( !--dword_1739981 )
    dword_1739981 = 287;
  v3 = *(_DWORD *)(a1 + 8);
  v7 = a2;
  if ( !--dword_1739986 )
    dword_1739986 = 675;
  if ( 0x3FFFFFFF - v3 >= a3 )
  {
    result = a3 + v3;
    *(_DWORD *)(a1 + 8) = result;
  }
  else
  {
    v4 = __readeflags();
    if ( !--dword_173998A )
      dword_173998A = 397;
    v5 = dword_16C696C ^ *(_DWORD *)((char *)&loc_459D0E + 1);
    __writeeflags(v4);
    _InterlockedExchange(&v7, v5);
    v10 = 15;
    v9 = 0;
    v8 = 0;
    return sub_406190();
  }
  return result;
}
