char __thiscall sub_499910(int this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int *v8; // ecx
  bool v9; // zf
  int v10; // ecx

  LOBYTE(v2) = *(_BYTE *)(this + 4);
  if ( (_BYTE)v2 )
  {
    *(_DWORD *)(this + 8) = 0;
    return v2;
  }
  while ( 1 )
  {
    v3 = *(_DWORD *)(this + 8);
    if ( v3 )
    {
      *(_DWORD *)(this + 8) = *(_DWORD *)(v3 + 140);
      goto LABEL_19;
    }
    if ( !*(_DWORD *)this )
      break;
    if ( *(_DWORD *)this == 1 )
    {
      v6 = *(_DWORD *)(this + 16);
      *(_DWORD *)this = 2;
      v7 = *(_DWORD *)(v6 + 72);
      *(_DWORD *)(this + 20) = v7;
      if ( v7 )
        *(_DWORD *)(this + 8) = *(_DWORD *)(v7 + 68);
      goto LABEL_19;
    }
    if ( *(_DWORD *)this == 2 )
    {
      if ( LinkedListNodeTraversal_98c0((_DWORD *)this) )
      {
        *(_DWORD *)(this + 8) = *(_DWORD *)(*(_DWORD *)(this + 20) + 68);
        goto LABEL_19;
      }
      LOBYTE(v2) = LinkedListIteratorAdvance((_DWORD *)this);
      if ( !(_BYTE)v2 )
        goto LABEL_22;
      v4 = *(_DWORD *)(this + 16);
      *(_DWORD *)this = 1;
      v5 = *(_DWORD *)(v4 + 76);
      goto LABEL_18;
    }
LABEL_19:
    LOBYTE(v2) = *(_BYTE *)(this + 4);
    if ( !(_BYTE)v2 )
    {
      v2 = *(_DWORD *)(this + 8);
      if ( !v2 )
        continue;
    }
    return v2;
  }
  v2 = *(_DWORD *)(this + 12) + 4;
  *(_DWORD *)this = 1;
  v8 = *(int **)v2;
  v9 = *(_DWORD *)v2 == 0;
  *(_DWORD *)(v2 + 8) = *(_DWORD *)v2;
  if ( v9 )
    v10 = 0;
  else
    v10 = *v8;
  *(_DWORD *)(this + 16) = v10;
  if ( v10 )
  {
    v5 = *(_DWORD *)(v10 + 76);
    *(_DWORD *)(this + 20) = 0;
LABEL_18:
    *(_DWORD *)(this + 8) = v5;
    goto LABEL_19;
  }
LABEL_22:
  *(_BYTE *)(this + 4) = 1;
  return v2;
}

