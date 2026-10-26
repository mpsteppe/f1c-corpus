int __stdcall sub_4D7E40(int a1, int a2, int a3, int a4, int a5, int a6, float a7, float a8)
{
  int result; // eax
  int v9; // esi
  float v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // edi
  float v14; // [esp+8h] [ebp-8h]
  int v15; // [esp+Ch] [ebp-4h]

  result = SwitchBasedGlobalLookup(a6);
  v9 = result;
  if ( result )
  {
    v10 = *(float *)(result + 92);
    v11 = *(_DWORD *)(result + 96);
    v12 = a4;
    *(float *)(v9 + 92) = a7 * v10;
    v14 = v10;
    v15 = v11;
    *(float *)(v9 + 96) = a8 * *(float *)(v9 + 96);
    FieldSetterAt0x48(v12);
    v13 = CRTFtol((double)a2 / a7);
    a2 = v13;
    a3 = CRTFtol((double)a3 / a8);
    if ( a5 == 1 )
    {
      SizeComputationWithSubtraction(a1, v13, &a2, a6);
    }
    else
    {
      if ( a5 != 2 )
      {
LABEL_7:
        result = sub_553070(a1, v13, a3, dword_8B8DC8);
        *(float *)(v9 + 92) = v14;
        *(_DWORD *)(v9 + 96) = v15;
        return result;
      }
      CenteredPosition(a1, v13, &a2, a6);
    }
    v13 = a2;
    goto LABEL_7;
  }
  return result;
}
