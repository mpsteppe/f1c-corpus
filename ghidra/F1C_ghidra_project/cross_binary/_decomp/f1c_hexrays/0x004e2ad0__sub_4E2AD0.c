// f1c  0x004e2ad0  size=411
void __stdcall sub_4E2AD0(void *a1, void *a2)
{
  void *v2; // ebx
  int v3; // edi
  void *v4; // esi
  int v5; // ebp
  int v6; // esi
  int v7; // ebx
  int i; // edi
  float *v9; // eax
  int v10; // [esp+8h] [ebp-20h]
  int v11; // [esp+Ch] [ebp-1Ch]
  float v12; // [esp+10h] [ebp-18h] BYREF
  float v13; // [esp+14h] [ebp-14h] BYREF
  float v14; // [esp+18h] [ebp-10h] BYREF
  float v15; // [esp+1Ch] [ebp-Ch] BYREF
  float v16; // [esp+20h] [ebp-8h]
  float v17; // [esp+24h] [ebp-4h]

  v2 = a1;
  if ( a1 )
  {
    sub_4DD550(a1, &v12, &v15);
    v3 = 0;
    v10 = 0;
    v14 = v17 + v14;
    v15 = (v15 + v12) * 0.5;
    v16 = (v16 + v13) * 0.5;
    v17 = v14 * 0.5;
    do
    {
      if ( v3 )
        v4 = a2;
      else
        v4 = v2;
      if ( v4 )
      {
        sub_54B420(&v12, &v13, &v14);
        v12 = v15 + v12;
        v13 = v16 + v13;
        v14 = v17 + v14;
        sub_54B3B0(LODWORD(v12), LODWORD(v13), LODWORD(v14));
        v5 = 0;
        v11 = sub_54C210(v4);
        if ( v11 > 0 )
        {
          do
          {
            v6 = sub_54C230(v5);
            v7 = sub_54E100(v6);
            for ( i = 0; i < v7; v9[2] = v9[2] - v17 )
            {
              v9 = (float *)sub_54E120(i++);
              *v9 = *v9 - v15;
              v9[1] = v9[1] - v16;
            }
            *(_DWORD *)(v6 + 20) &= 0xFEFFFFDF;
            sub_54D520(COERCE_FLOAT(1));
            sub_54E270(v6);
            sub_54D080(0);
            ++v5;
          }
          while ( v5 < v11 );
          v2 = a1;
          v3 = v10;
        }
      }
      v10 = ++v3;
    }
    while ( v3 < 2 );
  }
}
