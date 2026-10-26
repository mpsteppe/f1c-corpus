int __thiscall sub_53F81B(int *this, unsigned __int8 *a2, unsigned int a3, _DWORD *a4, int a5)
{
  int v5; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  unsigned int v13; // eax
  _DWORD *v14; // ecx
  _DWORD *v15; // ecx
  bool v16; // cf
  _DWORD *i; // eax
  int *j; // eax
  int v20; // ecx
  _DWORD v21[7]; // [esp+Ch] [ebp-20h]
  int v22; // [esp+28h] [ebp-4h]

  v5 = a3;
  v21[0] = 0;
  v21[1] = 5;
  v21[2] = 4;
  v21[3] = 1;
  v21[4] = 3;
  v21[5] = 2;
  v21[6] = 6;
  v22 = 0;
  do
  {
    this[16] = a5;
    v7 = v21[v22];
    this[18] = v7;
    this[17] = 3;
    if ( !v7 )
    {
      v13 = sub_53F7EB(this, (int)a2, a3);
      goto LABEL_16;
    }
    v8 = v7 - 1;
    if ( !v8 )
    {
      v13 = sub_53E528(this, (int)a2, a3);
      goto LABEL_16;
    }
    v9 = v8 - 1;
    if ( !v9 )
    {
      v13 = sub_53E798(this, a2, a3);
      goto LABEL_16;
    }
    v10 = v9 - 1;
    if ( !v10 )
    {
      v13 = sub_53EF14(this, (int)a2, a3);
      goto LABEL_16;
    }
    v11 = v10 - 1;
    if ( !v11 )
    {
      v13 = sub_53F4AA(this, (int)a2, a3);
      goto LABEL_16;
    }
    v12 = v11 - 1;
    if ( !v12 )
    {
      v13 = sub_53EC3F(this, a2, a3);
      goto LABEL_16;
    }
    if ( v12 == 1 )
    {
      v13 = sub_53DDCF(this, (int)a2, a3);
LABEL_16:
      v5 = v13;
    }
    if ( v5 >= 0 )
      break;
    if ( this[1] && this[14] )
      sub_5BE8AE();
    if ( this[2] && this[15] )
      sub_5BE8AE();
    v14 = (_DWORD *)this[19];
    if ( v14 )
      sub_53DDB3(v14, 1);
    v15 = (_DWORD *)this[20];
    if ( v15 )
      sub_53DDB3(v15, 1);
    v16 = (unsigned int)++v22 < 7;
    this[1] = 0;
    this[2] = 0;
    this[14] = 0;
    this[15] = 0;
    this[19] = 0;
    this[20] = 0;
  }
  while ( v16 );
  if ( v22 == 7 )
    return -2005529767;
  if ( a4 )
  {
    memset(a4, 0, 0x1Cu);
    *a4 = this[3];
    a4[1] = this[4];
    a4[2] = this[5];
    a4[3] = 1;
    a4[4] = sub_53D46A(*this);
    a4[5] = this[17];
    a4[6] = this[18];
    for ( i = this + 19; *i; i = (_DWORD *)(*i + 76) )
      ++a4[3];
  }
  do
  {
    for ( j = this; j; j = (int *)j[19] )
    {
      j[8] = j[3];
      j[9] = j[4];
      v20 = j[5];
      j[6] = 0;
      j[7] = 0;
      j[10] = 0;
      j[11] = v20;
    }
    this = (int *)this[20];
  }
  while ( this );
  return 0;
}
