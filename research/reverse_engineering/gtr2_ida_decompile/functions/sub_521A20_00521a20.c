int *__thiscall sub_521A20(int this, float a2)
{
  int *result; // eax
  int i; // esi
  char v5; // bl
  char v6; // [esp+7h] [ebp-1h]

  *(float *)(this + 48) = a2;
  result = *(int **)(this + 32);
  *(_DWORD *)(this + 40) = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      v6 = sub_599CD0(i);
      v5 = sub_599CF0(i);
      if ( !v6 || !v5 || a2 < (double)*(float *)(i + 860) || a2 > (double)*(float *)(i + 12) )
      {
        if ( v5 && a2 > (double)*(float *)(i + 12) )
        {
          sub_51BFA0((_DWORD *)(i + 856), (_DWORD *)(i + 8));
          sub_599CB0(i);
        }
        else if ( v6 && a2 < (double)*(float *)(i + 860) )
        {
          sub_51BFA0((_DWORD *)(i + 8), (_DWORD *)(i + 856));
          sub_599C90(i);
        }
        else
        {
          sub_59A9C0(i);
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
