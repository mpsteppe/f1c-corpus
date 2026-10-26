void __thiscall sub_427540(int this)
{
  int v2; // eax
  bool v3; // zf
  char v4; // cl
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // edi
  int v9; // ebx

  if ( (unsigned __int8)sub_4EED40(*(_DWORD *)(this + 80)) || *(_DWORD *)(this + 24240) == *(_DWORD *)(this + 23612) )
    return;
  if ( *(_DWORD *)(this + 20892) == 1 )
    sub_4271B0(this, 0);
  if ( *(_DWORD *)(this + 20892) == 3 )
    sub_4271B0(this, 0);
  if ( *(_DWORD *)(this + 19804) == 1 )
    sub_4271B0(this, 0);
  if ( *(int *)(this + 20900) > 0 )
    sub_4271B0(this, 0);
  v2 = sub_4FA870(0);
  if ( dword_7D7540 == 3 )
  {
    v3 = dword_6310D8[6326 * v2] == *(_DWORD *)(*(_DWORD *)(this + 80) + 20848);
  }
  else
  {
    if ( dword_7D7540 == 4 )
      goto LABEL_17;
    v3 = dword_7D7540 == 5;
  }
  if ( !v3 )
  {
    v4 = 0;
    goto LABEL_18;
  }
LABEL_17:
  v4 = 1;
LABEL_18:
  v5 = *(_DWORD *)(this + 24608);
  if ( v5 == -1 )
  {
    if ( (*(float *)(this + 18696) + *(float *)(this + 18448) + *(float *)(this + 18200) + *(float *)(this + 17952))
       * 0.25 >= 0.815
      || !v4 )
    {
      goto LABEL_25;
    }
  }
  else if ( !v4 || *(_DWORD *)(this + 20848) - *(_DWORD *)(this + 24604) < v5 / 2 - 1 )
  {
    goto LABEL_25;
  }
  sub_4271B0(this, 0);
LABEL_25:
  if ( dword_75CBB0 == 7 && sub_427F90(this) < 4 )
  {
    v6 = dword_7D74B8;
    v7 = *(_DWORD *)(this + 20848);
    if ( sub_427F90(this) < v6 - v7 )
      sub_4271B0(this, 0);
  }
  v8 = dword_7D74B8;
  v9 = *(_DWORD *)(this + 20848);
  if ( sub_427F90(this) < v8 - v9
    && (double)(dword_7D74B8 - *(_DWORD *)(this + 20848)) < *(float *)(this + 18796) * *(float *)(this + 17408) - 0.2 )
  {
    sub_4271B0(this, 0);
  }
}
