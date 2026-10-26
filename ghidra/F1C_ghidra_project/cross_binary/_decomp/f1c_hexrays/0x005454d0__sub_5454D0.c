// f1c  0x005454d0  size=283
int __thiscall sub_5454D0(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v4; // edi
  int *v5; // edx
  int v6; // ecx
  _DWORD *v7; // eax
  int i; // eax
  int v9; // eax
  void *v10; // ebp
  int v11; // edi
  int v12; // ebx
  int v13; // edi
  _DWORD *v14; // eax
  _DWORD *v15; // ebp
  int result; // eax
  _DWORD *v17; // ebx

  switch ( a3 )
  {
    case 1:
      v4 = this + 71;
      v5 = this + 72;
      break;
    case 2:
      v4 = this + 75;
      v5 = this + 76;
      break;
    case 4:
      v4 = this + 73;
      v5 = this + 74;
      break;
    default:
      v4 = a2;
      v5 = a2;
      break;
  }
  v6 = *v5;
  if ( *v5 )
  {
    for ( i = *(_DWORD *)(v6 + 108); i; i = *(_DWORD *)(i + 108) )
      v6 = i;
    v7 = a2;
    *(_DWORD *)(v6 + 108) = a2;
    a2[26] = v6;
  }
  else
  {
    v7 = a2;
    *v5 = (int)a2;
    a2[26] = 0;
  }
  ++*v4;
  v7[27] = 0;
  this[24] = this[73] + this[75];
  v9 = this[78];
  if ( v9 )
  {
    v10 = (void *)(v9 - 4);
    v11 = v9 + 56 * *(_DWORD *)(v9 - 4);
    if ( *(_DWORD *)(v9 - 4) - 1 >= 0 )
    {
      v12 = *(_DWORD *)(v9 - 4);
      do
      {
        v11 -= 56;
        nullsub_3();
        --v12;
      }
      while ( v12 );
    }
    sub_587BCF(v10);
    this[78] = 0;
    this[77] = 0;
  }
  v13 = this[24];
  v14 = (_DWORD *)sub_587C03(56 * v13 + 4);
  if ( v14 )
  {
    v15 = v14 + 1;
    *v14 = v13;
    result = v13 - 1;
    v17 = v15;
    if ( v13 - 1 >= 0 )
    {
      do
      {
        result = sub_55D200(v17);
        v17 += 14;
        --v13;
      }
      while ( v13 );
    }
    this[78] = v15;
  }
  else
  {
    result = 0;
    this[78] = 0;
  }
  return result;
}
