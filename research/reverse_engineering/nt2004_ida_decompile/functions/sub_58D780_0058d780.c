int __usercall sub_58D780@<eax>(unsigned int a1@<ebx>, int *a2)
{
  int v2; // edi
  int v3; // esi
  int v4; // ebx
  int v5; // ecx
  int v6; // eax
  int v7; // ebp
  int v8; // edi
  int v9; // eax
  __int16 v10; // cx
  unsigned int v11; // edx
  int result; // eax
  int v13; // [esp+10h] [ebp-10h] BYREF
  int v14; // [esp+14h] [ebp-Ch] BYREF
  int v15; // [esp+18h] [ebp-8h]
  int v16; // [esp+1Ch] [ebp-4h]

  v2 = -1;
  v16 = 0;
  v15 = -1;
  if ( !dword_7E4830 )
  {
    dword_7E4830 = 1;
    v14 = *a2;
    v3 = sub_58D520((unsigned __int16 *)&v14);
    if ( v3 )
    {
      if ( sub_58D600((int)&v14, &v13) )
      {
        LOBYTE(a1) = *(_BYTE *)(v3 + 10);
        v4 = (a1 >> 5) & 1;
        if ( v4 )
        {
          if ( !sub_58DA40(v13) )
            goto LABEL_22;
          v5 = v13;
          v2 = dword_7FFA80[v13];
          v15 = dword_7FFA60[v13];
          v6 = *(unsigned __int16 *)(dword_7FFAB0[24 * v2] + 4);
        }
        else
        {
          if ( (unsigned __int16)sub_58FAA0(100, -1) > *(char *)(v3 + 9) )
            goto LABEL_22;
          v5 = v13;
          v6 = *(unsigned __int16 *)(v3 + 4);
        }
        v7 = sub_58D950(v6, v5, v4);
        if ( v7 >= 0 )
        {
          v8 = sub_58FC30();
          if ( v8 == dword_7FF9E8 )
            ++word_7FF9E0;
          else
            word_7FF9E0 = 0;
          v9 = v13;
          v10 = word_7FF9E0;
          dword_7FF9E8 = v8;
          v11 = 96 * v7;
          dword_7FFAB0[v11 / 4] = v3;
          byte_7FFAAB[v11] = v9;
          word_7FFAA8[v11 / 2] = v10;
          dword_7FFAA4[v11 / 4] = v8;
          word_7FFAAC[v11 / 2] = v4;
          word_7FFAAE[v11 / 2] = -1;
          if ( v4 )
            word_7FFAAE[48 * v15] = v7;
          qmemcpy(&dword_7FFAB4[v11 / 4], a2, 0x50u);
          if ( !v4 )
            ++dword_7FFA40[v9];
          byte_7FFAAA[96 * v7] = 1;
          dword_7FFA60[v9] = v7;
          if ( !v4 )
            dword_7FFA80[v9] = v7;
          v16 = 1;
        }
        else if ( v4 )
        {
          sub_58DB10(v2);
        }
      }
    }
  }
LABEL_22:
  result = v16;
  dword_7E4830 = 0;
  return result;
}
