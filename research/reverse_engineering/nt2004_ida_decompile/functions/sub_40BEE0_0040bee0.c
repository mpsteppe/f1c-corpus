int __thiscall sub_40BEE0(int this, char a2)
{
  int result; // eax
  int v4; // ecx
  const char *v5; // eax
  int v6; // eax
  int v7; // edi
  int v8; // ebx
  float *v9; // eax
  float *v10; // eax
  float v11; // [esp+0h] [ebp-90h]
  float v12; // [esp+0h] [ebp-90h]
  float v13; // [esp+4h] [ebp-8Ch]
  float v14; // [esp+4h] [ebp-8Ch]
  _BYTE v15[4]; // [esp+18h] [ebp-78h] BYREF
  int v16; // [esp+1Ch] [ebp-74h] BYREF
  float v17; // [esp+20h] [ebp-70h]
  float v18; // [esp+24h] [ebp-6Ch]
  int v19; // [esp+28h] [ebp-68h] BYREF
  int v20; // [esp+2Ch] [ebp-64h]
  float v21; // [esp+30h] [ebp-60h]
  float v22; // [esp+34h] [ebp-5Ch]
  float v23; // [esp+38h] [ebp-58h]
  float v24; // [esp+40h] [ebp-50h]
  float v25; // [esp+44h] [ebp-4Ch]
  float v26; // [esp+48h] [ebp-48h] BYREF
  float v27; // [esp+4Ch] [ebp-44h] BYREF
  float v28; // [esp+50h] [ebp-40h] BYREF
  float v29; // [esp+54h] [ebp-3Ch] BYREF
  float v30; // [esp+58h] [ebp-38h]
  float v31; // [esp+5Ch] [ebp-34h]
  _BYTE v32[4]; // [esp+60h] [ebp-30h] BYREF
  _BYTE v33[4]; // [esp+64h] [ebp-2Ch] BYREF
  _BYTE v34[4]; // [esp+68h] [ebp-28h] BYREF
  float v35; // [esp+6Ch] [ebp-24h] BYREF
  float v36; // [esp+70h] [ebp-20h]
  float v37; // [esp+74h] [ebp-1Ch]
  float v38; // [esp+78h] [ebp-18h]
  float v39; // [esp+7Ch] [ebp-14h]
  float v40; // [esp+80h] [ebp-10h]
  float v41; // [esp+84h] [ebp-Ch]
  float v42; // [esp+88h] [ebp-8h]
  float v43; // [esp+8Ch] [ebp-4h]

  if ( !a2 )
    sub_593430(0);
  result = *(_DWORD *)(this + 44);
  if ( result && a2 )
  {
    v4 = *(_DWORD *)(this + 16);
    if ( !v4 )
      goto LABEL_16;
    v5 = (const char *)sub_459B80(v4);
    if ( _strcmpi(v5, aCockpit) || !*(_DWORD *)(this + 40) || *(_BYTE *)(this + 52) )
      goto LABEL_16;
    if ( *(_DWORD *)(this + 68) )
    {
      sub_593430(1);
      v6 = *(_DWORD *)(this + 68);
      v13 = (float)*(int *)(v6 + 32);
      v11 = (float)*(int *)(v6 + 28);
      sub_593B30(0.0, 0.0, v11, v13, 1);
      sub_593F30(*(_DWORD *)(this + 68));
      result = sub_593460(0);
      *(_BYTE *)(this + 72) = 0;
      return result;
    }
    if ( *(_DWORD *)(this + 48)
      && (sub_593E60(v15, v15, v15, &v16),
          v7 = *(_DWORD *)(dword_75AACC + 1896),
          v8 = dword_75AAC4,
          v8 == ((unsigned __int8)sub_42DBA0(&unk_62BF64) != 0 ? dword_75AACC : 0))
      && v7 )
    {
      sub_593430(1);
      sub_59E140(v32, v33, v34);
      sub_59E0C0(&v26, &v27, &v28);
      v9 = (float *)sub_59CB40(0);
      v21 = *v9;
      v22 = v9[1];
      v23 = v9[2];
      sub_579100(v32, &v35);
      v24 = v40 * v23 + v39 * v22 + v38 * v21;
      v25 = v43 * v23 + v42 * v22 + v41 * v21;
      v25 = v28 + v25;
      v31 = v25;
      v29 = v37 * v23 + v36 * v22 + v35 * v21 + v26;
      v30 = v27 + v24;
      sub_593F70(&v29, &v19);
      v20 = v16 - v20;
      v18 = (double)v19 / (double)dword_6152E8;
      v17 = (double)v20 / (double)dword_6152EC;
      v10 = (float *)sub_59CB40(3);
      v21 = *v10;
      v22 = v10[1];
      v23 = v10[2];
      sub_579100(v32, &v35);
      v24 = v40 * v23 + v39 * v22 + v38 * v21;
      v25 = v43 * v23 + v42 * v22 + v41 * v21;
      v25 = v28 + v25;
      v31 = v25;
      v29 = v37 * v23 + v36 * v22 + v35 * v21 + v26;
      v30 = v27 + v24;
      sub_593F70(&v29, &v19);
      v20 = v16 - v20;
      v14 = (double)v20 / (double)dword_6152EC - v17;
      v12 = (double)v19 / (double)dword_6152E8 - v18;
      sub_593B30(v18, v17, v12, v14, 0);
      sub_593F30(dword_7E8CDC);
      return sub_593460(1);
    }
    else
    {
LABEL_16:
      if ( byte_76617C || flt_7D79F4 > 0.0 )
      {
        return sub_593430(0);
      }
      else
      {
        sub_593B30(flt_768318, flt_76833C, flt_768360, flt_768384, 0);
        sub_593F30(dword_7E8CDC);
        sub_593460(1);
        return sub_593430(1);
      }
    }
  }
  return result;
}
