int __thiscall sub_4272D0(int this)
{
  char v2; // bl
  int result; // eax
  bool v4; // cl
  char *v5; // eax
  int v6; // ecx
  int v7; // eax
  float *v8; // ecx
  int v9; // edx
  int v10; // eax
  int v11; // edi
  int v12; // ebp
  bool v13; // zf
  signed int v14; // eax
  int v15; // edi
  int v16; // ebp

  v2 = 0;
  result = sub_4EED40(*(_DWORD *)(this + 80));
  if ( (_BYTE)result )
    return result;
  result = dword_7D7540;
  if ( dword_7D7540 )
    return result;
  result = *(_DWORD *)(this + 24240);
  if ( result == *(_DWORD *)(this + 23612) )
    return result;
  if ( *(_DWORD *)(16 * *(_DWORD *)(this + 24584) + this + 24504) <= *(_DWORD *)(*(_DWORD *)(this + 80) + 20848) )
    sub_4271B0(this, 0);
  if ( *(_DWORD *)(this + 20892) == 1 )
    sub_4271B0(this, 0);
  if ( *(_DWORD *)(this + 20892) == 3 )
    sub_4271B0(this, 0);
  if ( *(int *)(this + 20900) > 0 )
    sub_4271B0(this, 0);
  v4 = dword_6310D8[6326 * sub_4FA870(0)] == *(_DWORD *)(*(_DWORD *)(this + 80) + 20848);
  if ( *(float *)(this + 18800) * *(float *)(this + 18792) <= 0.5 && *(int *)dword_76926C > 0
    || (*(float *)(this + 18696) + *(float *)(this + 18448) + *(float *)(this + 18200) + *(float *)(this + 17952))
     * 0.25 < 0.85000002 )
  {
    if ( dword_7D7540 == 3 )
    {
      if ( !v4 )
        goto LABEL_21;
    }
    else if ( dword_7D7540 != 4 && dword_7D7540 != 5 )
    {
      goto LABEL_21;
    }
    v2 = 1;
  }
LABEL_21:
  v5 = (char *)sub_51E210(this + 84);
  v6 = sub_4BFFC0(v5);
  if ( flt_7DAB04 >= 0.25 )
    v7 = 5;
  else
    v7 = *(_DWORD *)(this + 24500);
  if ( v6 != v7 )
    v2 = 1;
  v8 = (float *)(this + 17952);
  v9 = 4;
  do
  {
    if ( *v8 < 0.75 )
      v2 = 1;
    v8 += 62;
    --v9;
  }
  while ( v9 );
  if ( (*(float *)(this + 18696) + *(float *)(this + 18448) + *(float *)(this + 18200) + *(float *)(this + 17952))
     * 0.25 < 0.85000002 )
    v2 = 1;
  v10 = *(_DWORD *)(this + 24608);
  if ( v10 == -1 )
  {
    if ( *(_DWORD *)(this + 19804) != 1 )
      goto LABEL_44;
    v14 = rand() & 0x80000001;
    v13 = v14 == 0;
    if ( v14 < 0 )
      v13 = (((_BYTE)v14 - 1) | 0xFFFFFFFE) == -1;
    if ( v13 )
      goto LABEL_44;
  }
  else
  {
    if ( *(_DWORD *)(this + 19804) == 1 && *(_DWORD *)(this + 20848) - *(_DWORD *)(this + 24604) < v10 - 5 )
      v2 = 1;
    v11 = dword_7D74B8;
    v12 = *(_DWORD *)(this + 20848);
    if ( sub_427F90(this) >= v11 - v12
      || *(_DWORD *)(this + 20848) - *(_DWORD *)(this + 24604) < *(_DWORD *)(this + 24608) - 1 )
    {
      goto LABEL_44;
    }
  }
  v2 = 1;
LABEL_44:
  result = sub_427F90(this);
  if ( result < 3 )
  {
    v15 = dword_7D74B8;
    v16 = *(_DWORD *)(this + 20848);
    result = sub_427F90(this);
    if ( result < v15 - v16 )
      return sub_4271B0(this, 0);
  }
  if ( v2 )
    return sub_4271B0(this, 0);
  return result;
}
