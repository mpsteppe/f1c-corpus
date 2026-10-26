int __thiscall sub_404680(int this)
{
  int v2; // eax
  double v3; // st7
  const char *v4; // eax
  FILE *v5; // eax
  FILE *v6; // ebx
  int v7; // eax
  int result; // eax
  double v9; // st7
  char v10; // [esp+0h] [ebp-8h]
  int v11; // [esp+4h] [ebp-4h]

  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_5, 2487) )
    sub_500FE0((int)&unk_7D7920, aEnteredAidatab, v10);
  v2 = 0;
  v11 = 0;
  do
  {
    if ( v2 )
      v3 = (double)v11;
    else
      v3 = 3.0;
    *(float *)(this + 4 * v2++ + 368) = v3;
    v11 = v2;
  }
  while ( v2 < 3 );
  *(_DWORD *)(this + 356) = 0;
  *(_DWORD *)(this + 360) = 0;
  *(_DWORD *)(this + 364) = 0;
  *(_DWORD *)(this + 424) = 7;
  *(_DWORD *)(this + 428) = 8;
  *(_DWORD *)(this + 336) = 1036831949;
  *(_DWORD *)(this + 344) = 1061997773;
  *(_DWORD *)(this + 348) = 1065353216;
  *(_DWORD *)(this + 352) = 1067030938;
  *(_DWORD *)(this + 408) = 48;
  *(_DWORD *)(this + 412) = 44;
  *(_DWORD *)(this + 416) = 1;
  *(_DWORD *)(this + 404) = 1;
  *(_DWORD *)(this + 8) = -1090519040;
  *(_DWORD *)(this + 12) = -1082130432;
  *(_DWORD *)(this + 48) = 0;
  *(_DWORD *)(this + 52) = 1065353216;
  *(_DWORD *)(this + 40) = 0;
  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)(this + 56) = 1083179008;
  *(_DWORD *)(this + 60) = 1082130432;
  *(_DWORD *)(this + 16) = 1025758986;
  *(_DWORD *)this = 1061997773;
  *(_DWORD *)(this + 4) = 1063172178;
  v4 = Source;
  if ( !Source )
    v4 = &byte_629120;
  strncpy((char *)(this + 80), v4, 0xC8u);
  v5 = fopen((const char *)(this + 80), Mode);
  v6 = v5;
  if ( v5 )
  {
    sub_402C00((char *)this, v5);
    fclose(v6);
  }
  v7 = dword_768684;
  if ( *(_DWORD *)dword_7689CC == 8 )
  {
    v7 = dword_7687EC;
  }
  else if ( *(_DWORD *)dword_7689CC == 4 )
  {
    v7 = dword_768834;
  }
  if ( v7 > 100 )
  {
    result = v7 - 100;
    v9 = (1.0 - (double)result * 0.050000001) * *(float *)(this + 348)
       + (double)result * 0.050000001 * *(float *)(this + 352);
  }
  else
  {
    result = v7 - 70;
    v9 = (1.0 - (double)result * 0.033333335) * *(float *)(this + 344)
       + (double)result * 0.033333335 * *(float *)(this + 348);
  }
  *(float *)(this + 340) = v9;
  return result;
}
