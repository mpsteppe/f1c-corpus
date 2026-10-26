char __thiscall sub_4ECE50(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  int v4; // ecx
  int *v5; // eax
  int v6; // eax

  v3 = this[24];
  if ( v3 )
  {
    v4 = a2;
    if ( a2 >= 0 && a2 < *(_DWORD *)(v3 + 64) )
    {
      v5 = *(int **)(v3 + 52);
      if ( a2 <= 0 )
      {
LABEL_7:
        if ( v5 )
        {
          v6 = *v5;
          if ( v6 )
          {
            *(_DWORD *)(v6 + 20) = a3;
            return 1;
          }
        }
      }
      else
      {
        while ( v5 )
        {
          v5 = (int *)v5[1];
          if ( --v4 <= 0 )
            goto LABEL_7;
        }
      }
    }
  }
  return 0;
}
