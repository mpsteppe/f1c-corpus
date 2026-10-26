void __thiscall sub_48D540(_DWORD *this)
{
  _DWORD *v2; // ecx
  int v3; // edx
  char Buffer[64]; // [esp+4h] [ebp-40h] BYREF

  v2 = (_DWORD *)this[210];
  if ( v2 )
  {
    v3 = this[212];
    if ( *v2 > v3 || (v3 = this[213], *v2 < v3) )
      *v2 = v3;
    sprintf(Buffer, "%d", *(_DWORD *)this[210]);
    sub_4CE770(Buffer);
  }
}
