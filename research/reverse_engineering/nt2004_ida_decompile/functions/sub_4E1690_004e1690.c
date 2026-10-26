int __thiscall sub_4E1690(int this)
{
  double v1; // st7
  CHAR *v2; // eax
  int result; // eax
  int v4; // esi
  int v5; // eax
  int v6; // edi
  int v7; // ebp
  double v8; // st7
  int v9; // ecx
  float v10; // [esp+4h] [ebp-8h]
  signed int i; // [esp+4h] [ebp-8h]

  v10 = (float)dword_768684;
  if ( *(_DWORD *)dword_7689CC == 8 )
  {
    v1 = (double)dword_7687EC;
  }
  else
  {
    if ( *(_DWORD *)dword_7689CC != 4 )
      goto LABEL_6;
    v1 = (double)dword_768834;
  }
  v10 = v1;
LABEL_6:
  v2 = dword_766594;
  if ( !dword_766594 )
    v2 = &byte_629120;
  sub_4E0F70(this, *(_DWORD *)(this + 420), *(float *)&v2, v10);
  result = 0;
  for ( i = 0; i < (int)NumOfElements; ++i )
  {
    v4 = dword_75AAD0[result];
    v5 = *(_DWORD *)(v4 + 16584);
    if ( v5 != -1 )
    {
      if ( v5 )
      {
        v6 = *(_DWORD *)(v4 + 20892);
        v7 = *(_DWORD *)(v4 + 20848);
        sub_4EE160(0.0);
        if ( v6 != 1 && v6 != 3 && v6 != 2 && v7 < *(_DWORD *)(this + 416) )
        {
          v8 = sub_4E1500(this, v4, *(float *)(this + 396));
          if ( *(_DWORD *)(v4 + 20848) < dword_7D74B8 )
          {
            do
            {
              v9 = *(_DWORD *)(v4 + 20848) + 1;
              *(_DWORD *)(v4 + 20848) = v9;
            }
            while ( v9 < dword_7D74B8 );
          }
          if ( *(float *)(v4 + 20960) <= 0.0 || v8 < *(float *)(v4 + 20960) )
            *(float *)(v4 + 20960) = v8;
          sub_4DC390((_DWORD *)(v4 + 20836));
        }
      }
    }
    result = i + 1;
  }
  return result;
}
