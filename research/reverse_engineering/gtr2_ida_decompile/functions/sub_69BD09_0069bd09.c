_DWORD *__thiscall sub_69BD09(_DWORD *this, _DWORD *a2)
{
  double *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // ebx
  int v6; // eax
  int v7; // edi
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  double *Block; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h]
  int v16; // [esp+14h] [ebp-4h]
  double *v17; // [esp+20h] [ebp+8h]

  if ( a2 && a2[1] == 13 )
  {
    v15 = a2[5] * a2[6];
    v3 = (double *)operator new(16 * v15);
    Block = v3;
    if ( v3 && sub_69A4A9(this, (int)a2, v3) >= 0 )
    {
      v4 = (_DWORD *)sub_65B229(80);
      v5 = v4 ? sub_67F5FE(v4, 0, 0, 0, 0, 1, a2 + 12) : 0;
      if ( v5 )
      {
        if ( !a2[4] || (v6 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)a2[4] + 4))(a2[4]), (v5[4] = v6) != 0) )
        {
          v16 = 0;
          v7 = (int)(v5 + 8);
          if ( !v15 )
          {
LABEL_22:
            sub_695BDE(this, v5);
LABEL_24:
            j__free(Block);
            return v5;
          }
          v17 = Block;
          while ( 1 )
          {
            v8 = (_DWORD *)sub_65B229(20);
            v9 = v8 ? sub_67ED1B(v8, 0, 0, (int)"Value") : 0;
            *(_DWORD *)v7 = v9;
            if ( !v9 )
              break;
            v10 = (_DWORD *)sub_65B229(64);
            v11 = v10 ? sub_67F6FF(v10, v17, a2 + 12) : 0;
            *(_DWORD *)(*(_DWORD *)v7 + 8) = v11;
            if ( !v11 )
              break;
            v17 += 2;
            v7 = *(_DWORD *)v7 + 12;
            if ( ++v16 >= v15 )
              goto LABEL_22;
          }
        }
      }
    }
    v5 = 0;
    goto LABEL_24;
  }
  return 0;
}
