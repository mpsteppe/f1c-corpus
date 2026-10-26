void __thiscall sub_5231D0(int this, float a2, float a3, char a4)
{
  int v4; // esi
  double v5; // st7
  double v6; // st7
  float **v7; // eax
  int **v8; // ebp
  int v9; // ebx
  float *v10; // eax
  float **v11; // eax
  int v12; // eax
  float **v13; // eax
  float *v14; // eax
  int v15; // edi
  int *v16; // eax
  bool v17; // zf
  int v18; // eax
  int *v19; // eax
  int v20; // eax
  int v21; // esi
  int v22; // eax
  int v23; // edx
  unsigned int v24; // eax
  _DWORD *v25; // ecx
  int *v26; // eax
  int *v27; // eax
  int v29; // [esp+18h] [ebp-35Ch] BYREF
  int v30; // [esp+1Ch] [ebp-358h]
  __int16 v31; // [esp+20h] [ebp-354h] BYREF
  int v32[212]; // [esp+24h] [ebp-350h] BYREF

  v4 = this;
  if ( a2 != a3 )
  {
    if ( a4 )
    {
      v5 = a3 - 1.6670001;
      if ( a2 < v5 )
        a2 = v5;
    }
    else
    {
      v6 = a2 + 1.6670001;
      if ( a3 > v6 )
        a3 = v6;
    }
    if ( (v7 = *(float ***)(this + 1892), v8 = (int **)(this + 1884), v9 = 0, v7) && (v10 = *v7) != 0
      || (*(float *)(this + 2892848) - *(float *)(this + 2892844) + *(float *)(this + 2892844) >= a2
        ? (v11 = (float **)*v8)
        : (v11 = *(float ***)(this + 1888)),
          (*(_DWORD *)(this + 1892) = v11) != 0 && (v10 = *v11) != 0) )
    {
      if ( *v10 <= (double)a2 )
      {
        while ( 1 )
        {
          v18 = *(_DWORD *)(this + 1892);
          if ( !v18 )
            break;
          v19 = *(int **)(v18 + 4);
          *(_DWORD *)(this + 1892) = v19;
          if ( !v19 )
            break;
          v15 = *v19;
          if ( !*v19 )
            break;
          if ( *(float *)v15 >= (double)a2 )
            goto LABEL_26;
        }
      }
      else
      {
        while ( 1 )
        {
          v12 = *(_DWORD *)(this + 1892);
          if ( !v12 )
            break;
          v13 = *(float ***)(v12 + 8);
          *(_DWORD *)(this + 1892) = v13;
          if ( !v13 )
            break;
          v14 = *v13;
          if ( !v14 )
            break;
          if ( *v14 < (double)a2 )
          {
            v15 = sub_473B70();
            goto LABEL_26;
          }
        }
        v16 = *v8;
        v17 = *v8 == 0;
        *(_DWORD *)(this + 1892) = *(_DWORD *)(this + 1884);
        if ( !v17 )
        {
          v15 = *v16;
LABEL_26:
          if ( v15 )
          {
            while ( *(float *)v15 <= (double)a3 )
            {
              v20 = *(_DWORD *)(v4 + 1780);
              v21 = v4 + 1780;
              (*(void (__thiscall **)(int, _DWORD))(v20 + 52))(v21, *(_DWORD *)(v15 + 4));
              v29 = 0;
              v30 = 0;
              v31 = 0;
              v22 = sub_614040(v21);
              v23 = *(_DWORD *)v21;
              v30 = v22;
              (*(void (__thiscall **)(int, int *, int))(v23 + 28))(v21, &v29, 4);
              (*(void (__thiscall **)(int, __int16 *, int))(*(_DWORD *)v21 + 28))(v21, &v31, 2);
              if ( *(_WORD *)(v15 + 8) )
              {
                do
                {
                  sub_5212F0(v21, *(float *)v15, (int)v32);
                  v24 = v32[0];
                  if ( *(_DWORD *)(this + 2892916) )
                  {
                    v24 = *(_DWORD *)(this + 2892924) | v32[0] & 0xFFFFFF00;
                    v32[0] = v24;
                  }
                  if ( (v24 & 0xE0000000) != 0x20000000 )
                  {
                    if ( dword_82F4A0 >= 1023 )
                    {
                      v25 = (_DWORD *)off_9034A4;
                    }
                    else
                    {
                      ++dword_82F4A0;
                      v25 = (_DWORD *)off_9034A4;
                      off_9034A4 += 848;
                    }
                    sub_51BFA0(v25, v32);
                  }
                  ++v9;
                }
                while ( v9 < *(unsigned __int16 *)(v15 + 8) );
              }
              v26 = v8[2];
              if ( v26 )
                v8[2] = (int *)v26[1];
              v27 = v8[2];
              if ( !v27 )
                break;
              v15 = *v27;
              if ( !*v27 )
                break;
              v4 = this;
              v9 = 0;
            }
          }
        }
      }
    }
  }
}
