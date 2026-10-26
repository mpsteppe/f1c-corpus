int *__thiscall sub_4B5380(int this, float a2)
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
      v6 = sub_5001D0(i);
      v5 = sub_5001F0(i);
      if ( !v6 || !v5 || *(float *)(i + 444) > (double)a2 || *(float *)(i + 12) < (double)a2 )
      {
        if ( v5 && *(float *)(i + 12) < (double)a2 )
        {
          sub_4B3A90((_DWORD *)(i + 440), (_DWORD *)(i + 8));
          sub_5001B0(i);
        }
        else if ( v6 && *(float *)(i + 444) > (double)a2 )
        {
          sub_4B3A90((_DWORD *)(i + 8), (_DWORD *)(i + 440));
          sub_500190(i);
        }
        else
        {
          sub_500170(i);
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
