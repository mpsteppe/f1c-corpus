int __thiscall sub_501CE0(_DWORD *this)
{
  int i; // edi
  int v3; // ecx
  int *v4; // eax
  int v5; // eax
  int v6; // edi
  _DWORD *v7; // ebp
  char v8; // al
  int result; // eax
  _DWORD *v10; // esi
  int v11; // edi

  for ( i = 0; i < this[21]; ++i )
  {
    v3 = i;
    if ( i >= 0 && i < this[21] )
    {
      v4 = (int *)this[18];
      if ( i <= 0 )
      {
LABEL_7:
        if ( v4 )
        {
          v5 = *v4;
          if ( v5 )
            sub_506920(v5);
        }
      }
      else
      {
        while ( v4 )
        {
          v4 = (int *)v4[1];
          if ( --v3 <= 0 )
            goto LABEL_7;
        }
      }
    }
  }
  v6 = this[18];
  while ( v6 )
  {
    v7 = (_DWORD *)v6;
    v8 = *(_BYTE *)(v6 + 8);
    v6 = *(_DWORD *)(v6 + 4);
    if ( v8 && *v7 )
    {
      sub_506920(*v7);
      sub_5BE8AE();
    }
    sub_5BE8AE();
  }
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  this[21] = 0;
  sub_502730(this);
  sub_5027D0(1);
  sub_5027D0(2);
  sub_5027D0(3);
  sub_5027D0(4);
  sub_5027D0(5);
  result = sub_5021C0(this);
  v10 = this + 9;
  v11 = 5;
  do
  {
    if ( *v10 )
      result = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v10 + 12))(*v10);
    ++v10;
    --v11;
  }
  while ( v11 );
  return result;
}
