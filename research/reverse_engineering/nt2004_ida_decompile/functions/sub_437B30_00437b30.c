int __thiscall sub_437B30(int *this, int a2, char *Source, const void *a4, const void *a5)
{
  int result; // eax
  int v7; // eax
  double v8; // st7
  int v9; // edi
  int v10; // edi
  _DWORD *v11; // eax
  _DWORD *v12; // esi
  int v13; // edi
  _DWORD *v14; // edx
  int v15; // edi
  int v16; // edx
  int v17; // edx
  int v18; // eax
  int v19; // edi
  int v20; // edi
  double v21; // st7
  _DWORD *v22; // [esp+Ch] [ebp-414h]
  int v23[2]; // [esp+10h] [ebp-410h] BYREF
  int v24[2]; // [esp+18h] [ebp-408h] BYREF
  int v25[2]; // [esp+20h] [ebp-400h] BYREF
  int v26[2]; // [esp+28h] [ebp-3F8h] BYREF
  _BYTE v27[28]; // [esp+34h] [ebp-3ECh] BYREF
  int v28[2]; // [esp+50h] [ebp-3D0h] BYREF
  int v29; // [esp+58h] [ebp-3C8h] BYREF
  int v30; // [esp+60h] [ebp-3C0h] BYREF
  double v31; // [esp+68h] [ebp-3B8h]
  double v32; // [esp+70h] [ebp-3B0h]
  double v33; // [esp+78h] [ebp-3A8h]
  double v34; // [esp+80h] [ebp-3A0h]
  double v35; // [esp+88h] [ebp-398h]
  double v36; // [esp+90h] [ebp-390h]
  double v37; // [esp+98h] [ebp-388h]
  double v38; // [esp+A0h] [ebp-380h]
  double v39; // [esp+A8h] [ebp-378h]
  double v40; // [esp+C0h] [ebp-360h]
  char String1[64]; // [esp+C8h] [ebp-358h] BYREF
  char String[384]; // [esp+108h] [ebp-318h] BYREF
  int v43; // [esp+288h] [ebp-198h]
  char v44; // [esp+28Ch] [ebp-194h]
  int v45; // [esp+294h] [ebp-18Ch]
  int v46; // [esp+298h] [ebp-188h]
  int v47; // [esp+29Ch] [ebp-184h]
  char Buffer[384]; // [esp+2A0h] [ebp-180h] BYREF

  sub_438010(this);
  result = a2;
  qmemcpy(this + 1, a4, 0x18u);
  qmemcpy(this + 19, a5, 0x18u);
  *this = a2;
  if ( a2 )
  {
    sub_57A080(v27);
    if ( (unsigned __int8)sub_57A2F0(Source, 1) )
    {
      memset(Buffer, 0, sizeof(Buffer));
      v43 = 0;
      v47 = 0;
      v45 = 0;
      v46 = 0;
      v44 = 1;
      if ( sub_57A490(Buffer, 384) )
      {
        while ( sub_577B60(String) )
        {
LABEL_39:
          if ( !sub_57A490(Buffer, 384) )
            return sub_57A0A0(v27);
        }
        if ( sub_578450(aHeadmass, (int)v26, 0, 0, 0) )
        {
          v7 = *this;
          v8 = *(double *)v26;
          *(double *)(v7 + 172) = *(double *)v26;
          *(double *)(v7 + 180) = 1.0 / v8;
        }
        if ( sub_578450(aHeadinertia, (int)v28, (int)&v29, (int)&v30, 0) )
          sub_57C530(v28);
        sub_578450(aMinpos, (int)(this + 7), (int)(this + 9), (int)(this + 11), 0);
        sub_578450(aMaxpos, (int)(this + 13), (int)(this + 15), (int)(this + 17), 0);
        if ( sub_578450(aMinori, (int)(this + 25), (int)(this + 27), (int)(this + 29), 0) )
        {
          *(double *)(this + 25) = *(double *)(this + 25) * 0.0174532925199433;
          *(double *)(this + 27) = *(double *)(this + 27) * 0.0174532925199433;
          *(double *)(this + 29) = *(double *)(this + 29) * 0.0174532925199433;
        }
        if ( sub_578450(aMaxori, (int)(this + 31), (int)(this + 33), (int)(this + 35), 0) )
        {
          *(double *)(this + 31) = *(double *)(this + 31) * 0.0174532925199433;
          *(double *)(this + 33) = *(double *)(this + 33) * 0.0174532925199433;
          *(double *)(this + 35) = *(double *)(this + 35) * 0.0174532925199433;
        }
        if ( sub_577ED0(String, aSpring, String1, 0) )
        {
          v9 = this[37];
          if ( this[38] >= v9 )
          {
            v10 = v9 + 3;
            this[37] = v10;
            v11 = operator new(100 * v10);
            v12 = v11;
            if ( v11 )
            {
              v13 = v10 - 1;
              v14 = v11;
              if ( v13 >= 0 )
              {
                v15 = v13 + 1;
                do
                {
                  sub_437AB0(v14);
                  v14 = (_DWORD *)(v16 + 100);
                  --v15;
                }
                while ( v15 );
              }
              v22 = v12;
            }
            else
            {
              v22 = 0;
            }
            v17 = 0;
            if ( this[38] > 0 )
            {
              v18 = 0;
              do
              {
                qmemcpy(&v22[v18], (const void *)(v18 * 4 + this[39]), 0x64u);
                ++v17;
                v18 += 25;
              }
              while ( v17 < this[38] );
            }
            if ( this[39] )
              sub_5BE8AE((LPVOID)this[39]);
            this[39] = (int)v22;
          }
          if ( !_strcmpi(String1, aSliding) )
          {
            *(_DWORD *)(100 * this[38] + this[39]) = 0;
LABEL_33:
            ++this[38];
            goto LABEL_34;
          }
          if ( !_strcmpi(String1, aNormal) )
          {
            *(_DWORD *)(100 * this[38] + this[39]) = 1;
            goto LABEL_33;
          }
          if ( !_strcmpi(String1, aFreedamping) )
          {
            *(_DWORD *)(100 * this[38] + this[39]) = 2;
            goto LABEL_33;
          }
        }
LABEL_34:
        v19 = this[38] - 1;
        if ( v19 >= 0 && v19 < this[37] )
        {
          v20 = this[39] + 100 * v19;
          sub_578450(aSpringdir, v20 + 4, v20 + 12, v20 + 20, 0);
          sub_578450(aSpringhead, v20 + 28, v20 + 36, v20 + 44, 0);
          if ( sub_578450(aSpringbody, (int)v23, (int)v24, (int)v25, 0) )
          {
            sub_57EAD0(this + 19);
            v40 = v37 * *(double *)v23 + v38 * *(double *)v24 + v39 * *(double *)v25;
            v21 = v34 * *(double *)v23 + v35 * *(double *)v24 + v36 * *(double *)v25;
            *(double *)(v20 + 52) = v32 * *(double *)v24
                                  + v33 * *(double *)v25
                                  + v31 * *(double *)v23
                                  + *(double *)(this + 1);
            *(double *)(v20 + 60) = v21 + *(double *)(this + 3);
            *(double *)(v20 + 68) = v40 + *(double *)(this + 5);
          }
          sub_578450(aSpringcolllen, v20 + 76, 0, 0, 0);
          sub_578450(aSpringparams, v20 + 84, v20 + 92, 0, 0);
        }
        goto LABEL_39;
      }
    }
    return sub_57A0A0(v27);
  }
  return result;
}
