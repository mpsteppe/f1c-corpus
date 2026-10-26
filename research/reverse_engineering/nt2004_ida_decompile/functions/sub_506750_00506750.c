int __thiscall sub_506750(_DWORD *this, int a2, char *Str, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // ebx
  int v12; // ecx
  int v13; // edx
  int v14; // eax
  int v16; // [esp+10h] [ebp-4h] BYREF

  v10 = 0;
  v16 = 0;
  sub_506920(this);
  if ( Str )
  {
    if ( a10 )
      sub_5924D0(dword_7DA988, (int)&v16, a10);
    if ( strcmp(Str, &byte_629120) && sub_5A29F0((int)(this + 1), Str, 0, 0, 0, 0, 2052, 1) )
      goto LABEL_13;
  }
  v12 = 0;
  v13 = 64;
  if ( this[8] == 1065353216 && this[9] == 1065353216 )
    v13 = 3136;
  v14 = this[1];
  if ( v14 )
    v12 = 32;
  if ( sub_5A1A60(this, 2, v14, v12, v13) )
  {
LABEL_13:
    v10 = 1;
  }
  else
  {
    this[5] = a7;
    this[6] = a8;
    this[7] = a2;
    sub_5069D0(a4, a5, a6, a9);
  }
  if ( v16 )
    sub_592750(v16);
  if ( v10 )
    sub_506920(this);
  return v10;
}
