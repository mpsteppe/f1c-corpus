int __thiscall sub_48A750(int this, int a2)
{
  double v3; // st7
  int *v4; // ecx
  int result; // eax
  float v6; // [esp+4h] [ebp-8h]

  v3 = *(float *)&a2 + *(float *)(this + 112);
  v4 = *(int **)(this + 152);
  result = *v4;
  a2 = *v4;
  if ( (int *)a2 != v4 )
  {
    do
    {
      sub_48A690();
      sub_476240(&a2);
      result = a2;
    }
    while ( a2 != *(_DWORD *)(this + 152) );
  }
  v6 = v3;
  *(float *)(this + 112) = v6 - (double)(int)(unsigned __int64)(v3 * 200.0) * 0.0049999999;
  return result;
}
