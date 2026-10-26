int *__thiscall sub_4D4C00(int this, float a2)
{
  int *result; // eax
  int i; // esi
  char v5; // bl
  char v6; // [esp+Fh] [ebp-1h]

  *(float *)(this + 48) = a2;
  result = *(int **)(this + 32);
  *(_DWORD *)(this + 40) = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      v6 = sub_52E830(i);
      v5 = sub_52E850(i);
      if ( !v6 || !v5 || *(float *)(i + 220) > (double)a2 || *(float *)(i + 12) < (double)a2 )
      {
        if ( v5 && *(float *)(i + 12) < (double)a2 )
        {
          sub_4D1850((_DWORD *)(i + 216), (_DWORD *)(i + 8));
          sub_52E810(i);
        }
        else if ( v6 && *(float *)(i + 220) > (double)a2 )
        {
          sub_4D1850((_DWORD *)(i + 8), (_DWORD *)(i + 216));
          sub_52E7F0(i);
        }
        else
        {
          sub_52E7D0(i);
        }
      }
      result = *(int **)(this + 40);
      if ( !result )
        break;
      result = (int *)result[1];
      *(_DWORD *)(this + 40) = result;
      if ( !result )
        break;
    }
  }
  return result;
}
