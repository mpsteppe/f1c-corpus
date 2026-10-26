int __thiscall sub_49F730(_DWORD *this, int a2, CHAR *a3, int a4, int a5, char a6)
{
  const char *v7; // eax
  char *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // esi
  CHAR *v11; // eax
  char Destination[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v14; // [esp+45h] [ebp-3h]
  char v15; // [esp+47h] [ebp-1h]

  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x3Cu);
  v14 = 0;
  v15 = 0;
  v7 = (const char *)this[44];
  if ( !v7 )
    v7 = &byte_629120;
  strncpy(Destination, v7, 0x3Fu);
  v15 = 0;
  v8 = strtok(Destination, word_5FBEBC);
  if ( v8 )
    this[90] = atoi(v8);
  if ( !a2 )
    return -1;
  v9 = operator new(0x120u);
  v10 = v9;
  if ( v9 )
  {
    sub_49C450(v9);
    v10[68] = 0;
    v10[69] = -1;
    v10[70] = 0;
    v10[71] = -1;
    *v10 = &off_5E9740;
  }
  else
  {
    v10 = 0;
  }
  sub_578600(a2);
  v11 = a3;
  if ( !a3 )
  {
    v11 = (CHAR *)this[42];
    if ( !v11 )
      v11 = &byte_629120;
  }
  sub_578600(v11);
  if ( a4 )
    sub_578600(a4);
  if ( a5 )
    sub_578600(a5);
  sub_49CA40(this, v10, a6);
  sub_49F5F0(this);
  (*(void (__thiscall **)(_DWORD *, int))(*this + 172))(this, a2);
  return 0;
}
