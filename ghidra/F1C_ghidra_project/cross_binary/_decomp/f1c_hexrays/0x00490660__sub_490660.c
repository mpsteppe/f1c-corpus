// f1c  0x00490660  size=118
int __thiscall sub_490660(_DWORD *this)
{
  int v2; // eax
  int result; // eax
  int i; // esi
  int v5; // ecx
  int *v6; // eax
  int v7; // eax
  bool v8; // [esp+8h] [ebp-4h]

  v8 = 0;
  v2 = sub_486720(this);
  if ( v2 >= 3 )
    v8 = v2 <= 5;
  result = this[59];
  for ( i = 0; i < result; ++i )
  {
    v5 = i;
    if ( i >= 0 && i < this[59] )
    {
      v6 = (int *)this[56];
      if ( i <= 0 )
      {
LABEL_9:
        if ( v6 )
        {
          v7 = *v6;
          if ( v7 )
            (*(void (__thiscall **)(int, bool))(*(_DWORD *)v7 + 16))(v7, v8);
        }
      }
      else
      {
        while ( v6 )
        {
          v6 = (int *)v6[1];
          if ( --v5 <= 0 )
            goto LABEL_9;
        }
      }
    }
    result = this[59];
  }
  return result;
}
