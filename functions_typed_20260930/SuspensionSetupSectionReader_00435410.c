int __thiscall sub_435410(int *this, int a2, int a3, const void *a4, const void *a5)
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
  double v23; // [esp+10h] [ebp-410h] BYREF
  double v24; // [esp+18h] [ebp-408h] BYREF
  double v25; // [esp+20h] [ebp-400h] BYREF
  double v26; // [esp+28h] [ebp-3F8h] BYREF
  _BYTE v27[28]; // [esp+34h] [ebp-3ECh] BYREF
  _BYTE v28[8]; // [esp+50h] [ebp-3D0h] BYREF
  char v29[8]; // [esp+58h] [ebp-3C8h] BYREF
  char v30[8]; // [esp+60h] [ebp-3C0h] BYREF
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
  CHAR v41[64]; // [esp+C8h] [ebp-358h] BYREF
  char v42[384]; // [esp+108h] [ebp-318h] BYREF
  int v43; // [esp+288h] [ebp-198h]
  char v44; // [esp+28Ch] [ebp-194h]
  int v45; // [esp+294h] [ebp-18Ch]
  int v46; // [esp+298h] [ebp-188h]
  int v47; // [esp+29Ch] [ebp-184h]
  _BYTE v48[384]; // [esp+2A0h] [ebp-180h] BYREF

  PhysicsBufferClear();
  result = a2;
  qmemcpy(this + 1, a4, 0x18u);
  qmemcpy(this + 19, a5, 0x18u);
  *this = a2;
  if ( a2 )
  {
    ZeroInitSmallStruct(v27);
    if ( (unsigned __int8)AudioStreamOpen(a3, 1) )
    {
      memset(v48, 0, sizeof(v48));
      v43 = 0;
      v47 = 0;
      v45 = 0;
      v46 = 0;
      v44 = 1;
      if ( ConditionalDispatchBasedOnFlag(v48, 384) )
      {
        while ( sub_5651B0(v42) )
        {
LABEL_39:
          if ( !ConditionalDispatchBasedOnFlag(v48, 384) )
            return SubCallWithConditionalFieldFree(v27);
        }
        if ( sub_565AA0(aHeadmass, &v26, 0, 0, 0) )
        {
          v7 = *this;
          v8 = v26;
          *(double *)(v7 + 172) = v26;
          *(double *)(v7 + 180) = 1.0 / v8;
        }
        if ( sub_565AA0(aHeadinertia, v28, v29, v30, 0) )
          StructCopyWithReciprocalDivision(v28);
        sub_565AA0(aMinpos, this + 7, this + 9, this + 11, 0);
        sub_565AA0(aMaxpos, this + 13, this + 15, this + 17, 0);
        if ( sub_565AA0(aMinori, this + 25, this + 27, this + 29, 0) )
        {
          *(double *)(this + 25) = *(double *)(this + 25) * 0.0174532925199433;
          *(double *)(this + 27) = *(double *)(this + 27) * 0.0174532925199433;
          *(double *)(this + 29) = *(double *)(this + 29) * 0.0174532925199433;
        }
        if ( sub_565AA0(aMaxori, this + 31, this + 33, this + 35, 0) )
        {
          *(double *)(this + 31) = *(double *)(this + 31) * 0.0174532925199433;
          *(double *)(this + 33) = *(double *)(this + 33) * 0.0174532925199433;
          *(double *)(this + 35) = *(double *)(this + 35) * 0.0174532925199433;
        }
        if ( sub_565520(aSpring, v41, 0) )
        {
          v9 = this[37];
          if ( this[38] >= v9 )
          {
            v10 = v9 + 3;
            this[37] = v10;
            v11 = (_DWORD *)OperatorNewNhMallocWrapper(100 * v10);
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
                  CategoryScoringStateInitializer(v14);
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
              FreeWrapper_7bcf((LPVOID)this[39]);
            this[39] = (int)v22;
          }
          if ( !sub_588410(v41, aSliding) )
          {
            *(_DWORD *)(100 * this[38] + this[39]) = 0;
LABEL_33:
            ++this[38];
            goto LABEL_34;
          }
          if ( !sub_588410(v41, aNormal) )
          {
            *(_DWORD *)(100 * this[38] + this[39]) = 1;
            goto LABEL_33;
          }
          if ( !sub_588410(v41, aFreedamping) )
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
          sub_565AA0(aSpringdir, v20 + 4, v20 + 12, v20 + 20, 0);
          sub_565AA0(aSpringhead, v20 + 28, v20 + 36, v20 + 44, 0);
          if ( sub_565AA0(aSpringbody, &v23, &v24, &v25, 0) )
          {
            EulerAnglesTo33RotationMatrix(this + 19);
            v40 = v37 * v23 + v38 * v24 + v39 * v25;
            v21 = v34 * v23 + v35 * v24 + v36 * v25;
            *(double *)(v20 + 52) = v32 * v24 + v33 * v25 + v31 * v23 + *(double *)(this + 1);
            *(double *)(v20 + 60) = v21 + *(double *)(this + 3);
            *(double *)(v20 + 68) = v40 + *(double *)(this + 5);
          }
          sub_565AA0(aSpringcolllen, v20 + 76, 0, 0, 0);
          sub_565AA0(aSpringparams, v20 + 84, v20 + 92, 0, 0);
        }
        goto LABEL_39;
      }
    }
    return SubCallWithConditionalFieldFree(v27);
  }
  return result;
}

