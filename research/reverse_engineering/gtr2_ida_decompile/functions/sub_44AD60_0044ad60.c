int __thiscall sub_44AD60(double *this, int a2, int a3, int *a4, int *a5)
{
  int result; // eax
  int v7; // eax
  double v8; // st7
  int v9; // edi
  int v10; // edi
  char *v11; // eax
  char *v12; // esi
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edi
  int v17; // edi
  char *v18; // [esp+0h] [ebp-558h]
  void *Block; // [esp+Ch] [ebp-54Ch] BYREF
  int v20[2]; // [esp+10h] [ebp-548h] BYREF
  int v21[5]; // [esp+1Ch] [ebp-53Ch] BYREF
  int v22[2]; // [esp+30h] [ebp-528h] BYREF
  int v23; // [esp+38h] [ebp-520h] BYREF
  char v24[4]; // [esp+3Ch] [ebp-51Ch] BYREF
  int v25; // [esp+40h] [ebp-518h] BYREF
  char v26[84]; // [esp+48h] [ebp-510h] BYREF
  char v27[12]; // [esp+9Ch] [ebp-4BCh] BYREF
  double v28[9]; // [esp+DCh] [ebp-47Ch] BYREF
  _BYTE v29[512]; // [esp+130h] [ebp-428h] BYREF
  int v30; // [esp+330h] [ebp-228h]
  char v31; // [esp+334h] [ebp-224h]
  char v32[4]; // [esp+33Ch] [ebp-21Ch] BYREF
  int v33; // [esp+340h] [ebp-218h]
  int v34; // [esp+344h] [ebp-214h]
  char Buffer[512]; // [esp+348h] [ebp-210h] BYREF
  int v36; // [esp+548h] [ebp-10h]
  int v37; // [esp+554h] [ebp-4h]

  sub_43B2D0(this);
  *((_DWORD *)this + 2) = *a4;
  *((_DWORD *)this + 3) = a4[1];
  *((_DWORD *)this + 4) = a4[2];
  *((_DWORD *)this + 5) = a4[3];
  *((_DWORD *)this + 6) = a4[4];
  *((_DWORD *)this + 7) = a4[5];
  *((_DWORD *)this + 20) = *a5;
  *((_DWORD *)this + 21) = a5[1];
  *((_DWORD *)this + 22) = a5[2];
  *((_DWORD *)this + 23) = a5[3];
  *((_DWORD *)this + 24) = a5[4];
  *((_DWORD *)this + 25) = a5[5];
  result = a2;
  *(_DWORD *)this = a2;
  if ( a2 )
  {
    sub_613B30(v26);
    v37 = 0;
    if ( (unsigned __int8)sub_614460(a3, 1) )
    {
      memset(Buffer, 0, sizeof(Buffer));
      v30 = 0;
      v34 = 0;
      *(_DWORD *)v32 = 0;
      v33 = 0;
      v31 = 1;
      if ( sub_613DE0(Buffer, 512) )
      {
        while ( sub_612EB0(v29) )
        {
LABEL_36:
          if ( !sub_613DE0(v32, 512) )
            goto LABEL_37;
        }
        if ( sub_6136D0("HeadMass", (int)v20, 0, 0, 0) )
        {
          v7 = *(_DWORD *)this;
          v8 = *(double *)v20;
          *(double *)(v7 + 176) = *(double *)v20;
          *(double *)(v7 + 184) = 1.0 / v8;
        }
        if ( sub_6136D0("HeadInertia", (int)v22, (int)&v23, (int)&v25, 0) )
          sub_619170(v22);
        sub_6136D0("MinPos", (int)(this + 4), (int)(this + 5), (int)(this + 6), 0);
        sub_6136D0("MaxPos", (int)(this + 7), (int)(this + 8), (int)(this + 9), 0);
        if ( sub_6136D0("MinOri", (int)(this + 13), (int)(this + 14), (int)(this + 15), 0) )
        {
          this[13] = this[13] * 0.0174532925199433;
          this[14] = this[14] * 0.0174532925199433;
          this[15] = this[15] * 0.0174532925199433;
        }
        if ( sub_6136D0("MaxOri", (int)(this + 16), (int)(this + 17), (int)(this + 18), 0) )
        {
          this[16] = this[16] * 0.0174532925199433;
          this[17] = this[17] * 0.0174532925199433;
          this[18] = this[18] * 0.0174532925199433;
        }
        if ( sub_6137E0(v29) )
        {
          v9 = *((_DWORD *)this + 38);
          if ( *((_DWORD *)this + 39) >= v9 )
          {
            v10 = v9 + 3;
            *((_DWORD *)this + 38) = v10;
            v11 = (char *)operator new(104 * v10);
            v12 = v11;
            LOBYTE(v36) = 1;
            if ( v11 )
            {
              sub_41D1B0((int)v11, 104, v10, (int)sub_43B250);
              v18 = v12;
            }
            else
            {
              v18 = 0;
            }
            v13 = *((_DWORD *)this + 39);
            v14 = 0;
            LOBYTE(v36) = 0;
            if ( v13 > 0 )
            {
              v15 = 0;
              do
              {
                qmemcpy(&v18[v15], (const void *)(v15 + *((_DWORD *)this + 40)), 0x68u);
                ++v14;
                v15 += 104;
              }
              while ( v14 < *((_DWORD *)this + 39) );
            }
            if ( *((_DWORD *)this + 40) )
              j_j__free(*((void **)this + 40));
            *((_DWORD *)this + 40) = v18;
          }
          if ( !_stricmp(v27, "SLIDING") )
          {
            *(_DWORD *)(104 * *((_DWORD *)this + 39) + *((_DWORD *)this + 40)) = 0;
LABEL_30:
            ++*((_DWORD *)this + 39);
            goto LABEL_31;
          }
          if ( !_stricmp(v27, "NORMAL") )
          {
            *(_DWORD *)(104 * *((_DWORD *)this + 39) + *((_DWORD *)this + 40)) = 1;
            goto LABEL_30;
          }
          if ( !_stricmp(v27, "FREEDAMPING") )
          {
            *(_DWORD *)(104 * *((_DWORD *)this + 39) + *((_DWORD *)this + 40)) = 2;
            goto LABEL_30;
          }
        }
LABEL_31:
        v16 = *((_DWORD *)this + 39) - 1;
        if ( v16 >= 0 && v16 < *((_DWORD *)this + 38) )
        {
          v17 = *((_DWORD *)this + 40) + 104 * v16;
          sub_6136D0("SpringDir", v17 + 8, v17 + 16, v17 + 24, 0);
          sub_6136D0("SpringHead", v17 + 32, v17 + 40, v17 + 48, 0);
          if ( sub_6136D0("SpringBody", (int)&Block, (int)&v20[1], (int)v21, 0) )
          {
            sub_61B860(this + 10);
            sub_43A370(v28, this + 1, (double *)&Block, (double *)(v17 + 56));
          }
          sub_6136D0("SpringCollLen", v17 + 80, 0, 0, 0);
          sub_6136D0("SpringParams", v17 + 88, v17 + 96, 0, 0);
        }
        goto LABEL_36;
      }
LABEL_37:
      sub_613C30(v24);
    }
    v36 = -1;
    return sub_614140(v24);
  }
  return result;
}
