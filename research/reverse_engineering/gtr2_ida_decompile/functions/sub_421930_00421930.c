int __thiscall sub_421930(_DWORD *this)
{
  int v2; // edi
  bool v3; // zf
  signed int v4; // eax
  int v5; // ebp
  int i; // esi
  const CHAR *v7; // eax

  if ( sub_592970(off_16C9B68) < 0.15000001 )
  {
    v2 = this[5229];
    goto LABEL_17;
  }
  if ( sub_592970(&dword_FB1EF8) < 0.2 )
  {
    v4 = rand() & 0x80000001;
    v3 = v4 == 0;
    if ( v4 < 0 )
      v3 = (((_BYTE)v4 - 1) | 0xFFFFFFFE) == -1;
    if ( !v3 )
    {
      v2 = this[5229];
      goto LABEL_17;
    }
    goto LABEL_9;
  }
  if ( sub_592970(&dword_FB1EF8) < 0.30000001 )
  {
LABEL_9:
    v2 = 5;
    goto LABEL_17;
  }
  if ( sub_592970(&dword_FB1EF8) >= 0.40000001 )
  {
    if ( sub_592970(&dword_FB1EF8) >= 0.69999999 )
    {
      if ( sub_592970(&dword_FB1EF8) >= 0.80000001 )
        v2 = 7;
      else
        v2 = 7 - (rand() % 2 != 0);
    }
    else
    {
      v2 = 6;
    }
  }
  else
  {
    v2 = (rand() % 2 != 0) + 5;
  }
LABEL_17:
  v5 = 0;
  for ( i = 0; i < *(_DWORD *)(this[4296] + 16); ++i )
  {
    v7 = *(const CHAR **)sub_560800(i);
    if ( !v7 )
      v7 = WindowName;
    if ( v2 == sub_4FB6D0(v7) )
      v5 = i;
  }
  return v5;
}
