int __thiscall sub_497F90(_DWORD *this, const char *a2)
{
  int result; // eax
  _BYTE *v4; // eax
  int v5; // esi
  _DWORD *i; // edi
  char v7[80]; // [esp+Ch] [ebp-50h] BYREF

  result = 0;
  if ( a2 )
  {
    if ( !strlen(a2) )
      return 0;
    strcpy(v7, a2);
    v4 = (_BYTE *)sub_587C20(v7, &dword_5CC79C);
    if ( v4 )
      *v4 = 0;
    v5 = 0;
    if ( (int)this[1349] > 0 )
    {
      for ( i = this + 69; sub_588410(i, v7); i += 20 )
      {
        if ( ++v5 >= this[1349] )
          return 0;
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
