// f1c  0x005385e0  size=213
int __fastcall sub_5385E0(int a1, int a2, int a3)
{
  int v4; // edx
  int v5; // ebp
  int result; // eax
  bool v7; // cc
  int v8; // edi
  int v9; // ebp
  unsigned __int16 v10; // dx
  unsigned __int16 v11; // bx
  int v12; // edi
  unsigned __int16 v13; // dx
  unsigned __int16 v14; // bx
  int v15; // edx
  int v16; // edx
  int v17; // [esp+10h] [ebp-4h]

  v4 = *(_DWORD *)(a1 + 5190);
  v5 = *(_DWORD *)(a1 + 4 * a3 + 2898);
  result = 2 * a3;
  v7 = 2 * a3 < v4;
  v17 = v5;
  if ( 2 * a3 > v4 )
  {
    *(_DWORD *)(a1 + 4 * a3 + 2898) = v5;
  }
  else
  {
    while ( 1 )
    {
      if ( v7 )
      {
        v8 = *(_DWORD *)(a1 + 4 * result + 2902);
        v9 = *(_DWORD *)(a1 + 4 * result + 2898);
        v10 = *(_WORD *)(a2 + 4 * v8);
        v11 = *(_WORD *)(a2 + 4 * v9);
        if ( v10 < v11 || v10 == v11 && *(_BYTE *)(v8 + a1 + 5198) <= *(_BYTE *)(a1 + v9 + 5198) )
          ++result;
        v5 = v17;
      }
      v12 = *(_DWORD *)(a1 + 4 * result + 2898);
      v13 = *(_WORD *)(a2 + 4 * v5);
      v14 = *(_WORD *)(a2 + 4 * v12);
      if ( v13 < v14 )
      {
LABEL_12:
        result = a3;
        *(_DWORD *)(a1 + 4 * a3 + 2898) = v5;
        return result;
      }
      if ( v13 == v14 && *(_BYTE *)(a1 + v5 + 5198) <= *(_BYTE *)(v12 + a1 + 5198) )
        break;
      v15 = a3;
      a3 = result;
      result *= 2;
      *(_DWORD *)(a1 + 4 * v15 + 2898) = v12;
      v16 = *(_DWORD *)(a1 + 5190);
      v7 = result < v16;
      if ( result > v16 )
        goto LABEL_12;
    }
    *(_DWORD *)(a1 + 4 * a3 + 2898) = v5;
  }
  return result;
}
