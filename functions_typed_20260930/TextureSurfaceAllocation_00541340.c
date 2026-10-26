int __thiscall sub_541340(int this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  _DWORD *v5; // edi
  _DWORD *v6; // eax
  int v7; // edx
  int result; // eax

  v3 = (_DWORD *)OperatorNewNhMallocWrapper(76);
  v4 = 0;
  if ( v3 )
  {
    v5 = v3 + 1;
    *v3 = 2;
    v6 = v3 + 1;
    v7 = 2;
    do
    {
      v6[5] = 0;
      v6[4] = 0;
      v6[3] = 0;
      v6[2] = 0;
      v6[1] = 0;
      *v6 = 0;
      v6[7] = 0;
      v6[6] = 0;
      v6[8] = 0;
      v6 += 9;
      --v7;
    }
    while ( v7 );
    v4 = v5;
  }
  *(_DWORD *)(this + 4428) = v4;
  *v4 = 34;
  *(_DWORD *)(*(_DWORD *)(this + 4428) + 12) = a2;
  *(_DWORD *)(*(_DWORD *)(this + 4428) + 4) = 322;
  *(_DWORD *)(*(_DWORD *)(this + 4428) + 8) = 24;
  *(_DWORD *)(*(_DWORD *)(this + 4428) + 36) = 34;
  *(_DWORD *)(*(_DWORD *)(this + 4428) + 48) = a2;
  *(_DWORD *)(*(_DWORD *)(this + 4428) + 40) = 322;
  *(_DWORD *)(*(_DWORD *)(this + 4428) + 44) = 24;
  if ( sub_540DF0((int *)this, *(int **)(this + 4428)) )
    return -1;
  result = sub_540DF0((int *)this, (int *)(*(_DWORD *)(this + 4428) + 36));
  if ( result )
    return -1;
  return result;
}

