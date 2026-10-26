void __thiscall sub_4E9CA0(float *this)
{
  unsigned __int8 v3; // c0
  unsigned __int8 v4; // c2
  int v5; // ebp
  float *v6; // eax
  float *v7; // ebx
  int v8; // ecx
  int v9; // edx
  int v10; // edi
  float *v11; // edi
  int v12; // ecx
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c2
  int v16; // edx
  unsigned __int8 v18; // c0
  unsigned __int8 v19; // c2
  int v20; // ecx
  float *v21; // eax
  int v22; // edx
  int v23; // eax
  int v24; // ecx
  int v25; // [esp+10h] [ebp-48h]
  int v26; // [esp+14h] [ebp-44h]
  int v27; // [esp+18h] [ebp-40h]
  float v28; // [esp+1Ch] [ebp-3Ch] BYREF
  int v29; // [esp+28h] [ebp-30h] BYREF
  int v30; // [esp+34h] [ebp-24h] BYREF
  _DWORD v31[3]; // [esp+40h] [ebp-18h] BYREF
  _DWORD v32[3]; // [esp+4Ch] [ebp-Ch] BYREF

  if ( sub_4BC340((_DWORD *)(*(_DWORD *)this + 16436)) )
  {
    F_3DTransformWithMatrixMultiplication(&v29, v31);
    RenderCallWithGuard(*(_DWORD **)this, &v30, v32);
    if ( !(v3 | v4) )
    {
      v5 = 2 * dword_5EA3F0;
      v25 = 2 * dword_5EA3F0;
      v6 = sub_403640(dword_5EA2C0, this + 3381, 0);
      *((_DWORD *)this + 3751) = v6;
      v7 = v6;
      v8 = *(_DWORD *)(*(_DWORD *)this + 16448);
      v9 = 0;
      if ( *((_DWORD *)v6 + 17) != v8 )
      {
        do
        {
          v5 = v25;
          v7 = (float *)*((_DWORD *)v7 + 67);
          v10 = v9++;
          if ( v10 > v25 )
            return;
        }
        while ( *((_DWORD *)v7 + 17) != v8 );
      }
      RenderCallWithGuard(*(_DWORD **)this, &v29, v31);
      CoordinateTransformWithOffset(&v30, v32, &v28);
      v11 = sub_403640(dword_5EA2C0, &v28, 0);
      v12 = 0;
      if ( v14 | v15 )
      {
        do
        {
          v11 = (float *)*((_DWORD *)v11 + 67);
          v16 = v12++;
          if ( v16 > v5 )
            return;
        }
        while ( v18 | v19 );
      }
      v20 = 0;
      if ( *((_BYTE *)this + 13376) )
      {
        v21 = v7;
        while ( v21 != v11 )
        {
          if ( *((_DWORD *)v21 + 75) )
          {
            v21 = (float *)*((_DWORD *)v21 + 68);
            v22 = v20++;
            if ( v22 <= v25 )
              continue;
          }
          return;
        }
      }
      this[3384] = *(float *)v31;
      this[3385] = *(float *)&v31[1];
      this[3386] = *(float *)&v31[2];
      EulerToRotationMatrix(this + 3384, this + 3372);
      v26 = 1;
      v27 = 0;
      while ( 1 )
      {
        this[3381] = *v7;
        this[3382] = v7[1];
        this[3383] = v7[2];
        SuspensionStateUpdate((int)this);
        *(_DWORD *)(*(_DWORD *)this + 16532) = 1;
        VehicleBodyToWheelContactDistanceComputation(this, 0);
        F_3x3MatrixTransformWithTranslation(this);
        BufferEntryClear(0x8000000);
        if ( dword_8AD07C )
        {
          SceneNodeVisibilityToggle(1);
          UIFocusChange(dword_8AD07C, 1);
          SceneNodeVisibilityToggle(0);
        }
        if ( dword_8AD080 )
        {
          SceneNodeVisibilityToggle(1);
          UIFocusChange(dword_8AD080, 1);
          SceneNodeVisibilityToggle(0);
        }
        if ( dword_8AD084 )
        {
          SceneNodeVisibilityToggle(1);
          UIFocusChange(dword_8AD084, 1);
          SceneNodeVisibilityToggle(0);
        }
        if ( v26 != 1 )
          break;
        if ( v7 == v11 )
          v26 = 2;
        v23 = *((_DWORD *)v7 + 69);
        if ( !v23 || *(_DWORD *)(v23 + 300) != 1 )
          goto LABEL_29;
        v7 = (float *)*((_DWORD *)v7 + 69);
LABEL_30:
        v24 = v27++;
        if ( v24 > v25 )
        {
LABEL_31:
          BufferEntryClear(0x8000000);
          return;
        }
      }
      if ( !*((_DWORD *)v7 + 17) )
        goto LABEL_31;
LABEL_29:
      v7 = (float *)*((_DWORD *)v7 + 68);
      goto LABEL_30;
    }
  }
}

