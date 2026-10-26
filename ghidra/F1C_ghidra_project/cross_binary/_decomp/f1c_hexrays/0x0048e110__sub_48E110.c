// f1c  0x0048e110  size=310
int __thiscall sub_48E110(_DWORD *this)
{
  int v2; // eax
  _DWORD *v3; // ebp
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // edx
  char v9; // cl
  const char *v10; // edi
  int v11; // eax
  bool v12; // zf
  char v14[128]; // [esp+10h] [ebp-80h] BYREF

  v2 = this[56];
  v3 = this + 56;
  if ( v2 )
  {
    sub_551F80(v2);
    *v3 = 0;
  }
  v4 = (char *)this[44];
  if ( !v4 )
    v4 = byte_5EA438;
  this[57] = sub_551F10(v3, v4, 0, 0);
  v5 = (char *)this[44];
  if ( !v5 )
    v5 = byte_5EA438;
  sub_566650(v5);
  if ( this[57] )
  {
    v6 = (char *)this[44];
    if ( !v6 )
      v6 = byte_5EA438;
    sub_566650(v6);
    v7 = (char *)dword_5EC3F0;
    if ( !dword_5EC3F0 )
      v7 = byte_5EA438;
    v8 = (char *)(v14 - v7);
    do
    {
      v9 = *v7;
      v7[(_DWORD)v8] = *v7;
      ++v7;
    }
    while ( v9 );
    v10 = (const char *)this[44];
    if ( !v10 )
      v10 = byte_5EA438;
    strcat(v14, v10);
    v11 = sub_551F10(v3, v14, 0, 0);
    v12 = *v3 == 0;
    this[57] = v11;
    if ( !v12 )
      sub_551EB0(flt_7CF2CC);
  }
  return 0;
}
