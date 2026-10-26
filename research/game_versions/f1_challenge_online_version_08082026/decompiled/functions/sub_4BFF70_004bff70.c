void sub_4BFF70()
{
  int v0; // esi
  float v1; // ebp
  char *v2; // ebx
  int v3; // edi
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  int v7; // ebx
  _DWORD *v8; // eax
  float *v9; // ecx
  int v10; // edi
  float *v11; // ebx
  float *v12; // ecx
  int v13; // ebp
  int v14; // ecx
  int v15; // ebx
  _DWORD *v16; // edi
  int v17; // esi
  int v18; // edi
  int v19; // [esp+10h] [ebp-4F4h]
  int v20; // [esp+14h] [ebp-4F0h]
  int v21; // [esp+18h] [ebp-4ECh]
  int v22; // [esp+1Ch] [ebp-4E8h]
  int v23; // [esp+20h] [ebp-4E4h]
  float v25[311]; // [esp+28h] [ebp-4DCh] BYREF

  if ( dword_7D0410 > 0 && dword_7D0410 <= 5 )
  {
    v0 = dword_5C329C;
    v18 = 0;
    v20 = 0;
    if ( dword_7D0110 == dword_7D011C )
    {
      v1 = 0.0;
      if ( dword_5C329C > 0 )
      {
        do
        {
          if ( v1 == 0.0 && sub_42BC10() )
          {
            v2 = (char *)dword_7CE668;
            if ( !dword_7CE668 )
              v2 = byte_5EA438;
          }
          else
          {
            v2 = (char *)&unk_5F0CF8 + 18624 * LODWORD(v1);
          }
          SLODWORD(v25[3 * LODWORD(v1) - 1]) = sub_4C0260(v2);
          v25[3 * LODWORD(v1)] = sub_4C02D0(v2);
          v25[3 * LODWORD(v1)++ + 1] = v1;
        }
        while ( SLODWORD(v1) < v0 );
      }
      v3 = 0;
      if ( v0 > 0 )
      {
        v4 = 0;
        v19 = 0;
        do
        {
          v5 = v3;
          v6 = v3;
          if ( v3 < v0 )
          {
            v7 = v4;
            do
            {
              if ( *(int *)((char *)&v25[-1] + v4) < *(int *)((char *)&v25[-1] + v7) )
              {
                v5 = v6;
                v7 = v4;
              }
              ++v6;
              v4 += 12;
            }
            while ( v6 < v0 );
            v4 = v19;
          }
          v8 = (int *)((char *)&v25[-1] + v4);
          v21 = *(int *)((char *)&v25[-1] + v4);
          v23 = *(_DWORD *)((char *)&v25[1] + v4);
          v9 = &v25[3 * v5 - 1];
          v22 = *(int *)((char *)v25 + v4);
          *v8 = *(_DWORD *)v9;
          v8[1] = *((_DWORD *)v9 + 1);
          v8[2] = *((_DWORD *)v9 + 2);
          *(_DWORD *)v9 = v21;
          *((_DWORD *)v9 + 1) = v22;
          ++v3;
          v4 += 12;
          *((_DWORD *)v9 + 2) = v23;
          v19 = v4;
        }
        while ( v3 < v0 );
        v10 = 1;
        v11 = v25;
        do
        {
          v12 = (float *)((char *)&unk_5F070C + 18624 * *((_DWORD *)v11 + 1));
          v12[10] = *v11;
          *((_DWORD *)v12 + 9) = v10;
          sub_4BC2F0((int)v12, v10);
          v11 += 3;
          ++v10;
        }
        while ( v10 - 1 < v0 );
      }
    }
    else
    {
      v13 = -1;
      v15 = 1;
      if ( sub_42BC10() )
      {
        v13 = dword_7D0110;
        v20 = 1;
        if ( !dword_7D0110 )
          v13 = sub_5884ED(v14) % v0 + 1;
        if ( v13 >= 1 )
        {
          if ( v13 > v0 )
            v13 = v0;
        }
        else
        {
          v13 = 1;
        }
        *(_DWORD *)(dword_7C54E8 + 16472) = v13;
        *(_DWORD *)(dword_7C54E8 + 16476) = -1082130432;
        sub_4BC2F0(dword_7C54E8 + 16436, v13);
        v18 = 1;
      }
      if ( v18 < v0 )
      {
        v16 = (_DWORD *)((char *)&unk_5F0734 + 18624 * v18);
        v17 = v0 - v20;
        do
        {
          if ( v15 == v13 )
            ++v15;
          *(v16 - 1) = v15;
          *v16 = -1082130432;
          sub_4BC2F0((int)(v16 - 10), v15++);
          v16 += 4656;
          --v17;
        }
        while ( v17 );
      }
    }
  }
}
