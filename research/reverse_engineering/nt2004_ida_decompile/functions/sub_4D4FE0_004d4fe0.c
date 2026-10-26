int *__thiscall sub_4D4FE0(int this)
{
  int *result; // eax
  int i; // esi
  int v4[52]; // [esp+8h] [ebp-D0h] BYREF

  result = *(int **)(this + 32);
  *(_DWORD *)(this + 40) = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      if ( (unsigned __int8)sub_52E830(i)
        && (unsigned __int8)sub_52E850(i)
        && (unsigned __int8)sub_52E870(*(float *)(this + 48), (int)v4, 0.0) )
      {
        *(float *)(i + 432) = *(float *)&v4[1];
        sub_418020(dword_6291D0, (int)v4);
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
