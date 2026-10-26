char __userpurge sub_59AFE0@<al>(
        float *a1@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        float a4,
        int a5,
        float *a6,
        int a7,
        int a8)
{
  char result; // al
  bool v10; // zf
  double v11; // st7
  double v12; // st7
  float *v13; // edi
  char v14; // al
  char v15; // bl
  int v16; // ebp
  float v17; // [esp+0h] [ebp-36Ch]
  int v18[4]; // [esp+Ch] [ebp-360h] BYREF
  int v19[211]; // [esp+1Ch] [ebp-350h] BYREF
  int v20; // [esp+368h] [ebp-4h]
  float retaddr; // [esp+36Ch] [ebp+0h]

  result = 0;
  if ( *((_DWORD *)a1 + 3) != 2123789977 )
  {
    v10 = *((_DWORD *)a1 + 215) == -23693671;
    v18[2] = a2;
    v18[1] = a3;
    if ( v10 || (v11 = a1[215], v11 >= a4) )
    {
      v13 = a6;
      v14 = sub_599D10(a4, (int)(a1 + 2), (int)a6, 1.0);
    }
    else
    {
      v12 = a4 - v11;
      if ( v12 >= 0.001 )
      {
        if ( v12 > 0.5 )
          v12 = 0.5;
      }
      else
      {
        v12 = 0.001;
      }
      v17 = v12 + a4;
      sub_599D10(v17, (int)(a1 + 2), (int)v19, 1.0);
      v13 = (float *)v20;
      v14 = sub_59A1A0(a1, v19[209], (int)(a1 + 214), (int)v18, v20);
    }
    v15 = v14;
    sub_51BFA0((_DWORD *)a1 + 214, v13);
    if ( v15 && LOBYTE(a4) )
    {
      v16 = sub_615460(512);
      sub_599C10(v13, retaddr);
      if ( v16 != 512 )
        sub_6154A0(v16);
      return v15;
    }
    else
    {
      return v15;
    }
  }
  return result;
}
