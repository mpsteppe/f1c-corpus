int __stdcall sub_4E2190(int a1)
{
  int result; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  char v10; // [esp+Fh] [ebp-9h]
  int v11; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h]
  int v13; // [esp+1Ch] [ebp+4h]

  result = dword_75CBB0;
  v3 = NumOfElements;
  v4 = 0;
  v11 = dword_75CBB0;
  v10 = 0;
  v12 = *(_DWORD *)(a1 + 20884);
  v13 = 1;
  if ( (int)NumOfElements >= 1 )
  {
    while ( 1 )
    {
      v5 = 0;
      if ( v3 > 0 )
        break;
LABEL_21:
      result = ++v13;
      if ( v13 > v3 )
        return result;
    }
    while ( 1 )
    {
      v6 = dword_75AAD0[v5];
      v7 = *(_DWORD *)(v6 + 20884);
      if ( v7 == v13 )
      {
        if ( v6 == a1 )
          goto LABEL_18;
        if ( !v10 )
        {
          if ( v11 == 7 )
          {
            v8 = *(_DWORD *)(v6 + 20848);
            v9 = *(_DWORD *)(a1 + 20848);
            if ( v8 >= v9 && (v8 != v9 || *(float *)(a1 + 20956) >= (double)*(float *)(v6 + 20956)) )
              goto LABEL_19;
          }
          else if ( *(float *)(a1 + 20960) >= (double)*(float *)(v6 + 20960) && *(float *)(v6 + 20960) >= 0.0 )
          {
            goto LABEL_19;
          }
          v10 = 1;
          if ( *(_DWORD *)(a1 + 20884) - 1 == v7 )
            v13 = v3 + 1;
          v4 = v6;
          sub_4DEB20((int *)(a1 + 20836), v7);
          sub_4DEB20((int *)(v6 + 20836), *(_DWORD *)(v6 + 20884) + 1);
          goto LABEL_19;
        }
        if ( v4 != v6 )
        {
          v4 = dword_75AAD0[v5];
          sub_4DEB20((int *)(v6 + 20836), v7 + 1);
          if ( v12 == *(_DWORD *)(v6 + 20884) )
LABEL_18:
            v13 = v3 + 1;
LABEL_19:
          v5 = v3;
        }
      }
      if ( ++v5 >= v3 )
        goto LABEL_21;
    }
  }
  return result;
}
