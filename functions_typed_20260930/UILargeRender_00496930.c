int __thiscall sub_496930(int this)
{
  int v2; // ebx
  int v3; // ebp
  int v4; // edi
  int v5; // eax
  double v6; // st7
  int v7; // ecx
  char *v8; // eax
  int v9; // eax
  char *v10; // eax
  int v11; // eax
  char *v12; // eax
  int v13; // eax
  _DWORD *v14; // edi
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  int v18; // eax
  _DWORD *v19; // edi
  char *v20; // eax
  char *v21; // eax
  int v22; // ecx
  int v23; // ecx
  char *v24; // eax
  int v25; // eax
  int v26; // edx
  int v27; // ecx
  int v28; // edx
  int v29; // eax
  int v30; // ecx
  int v31; // edx
  int v32; // eax
  int v33; // ecx
  int v35; // [esp+10h] [ebp-4h]

  CollisionSpeedSetter();
  if ( *(_DWORD *)(this + 40) != 2 )
    *(_DWORD *)(this + 40) = 2;
  if ( !(unsigned __int8)sub_496E20(this) )
  {
    InitViewportDimensions(this);
    v2 = *(_DWORD *)(this + 92);
    v3 = *(_DWORD *)(this + 5484);
    v4 = *(_DWORD *)(this + 24);
    v35 = *(_DWORD *)(this + 96);
    v5 = CollisionResponseTypeClassification(this);
    *(_DWORD *)(this + 116) = v5;
    switch ( v5 )
    {
      case 1:
      case 2:
      case 4:
      case 6:
      case 9:
        *(_DWORD *)(this + 5484) = 0;
        break;
      default:
        break;
    }
    if ( !*(_DWORD *)(this + 5484) )
      *(_DWORD *)(this + 5484) = ObjectSearchWithDoubleIteration((_DWORD *)this);
    if ( v3 != *(_DWORD *)(this + 5484) && v3 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 76))(v3);
    if ( v4 != *(_DWORD *)(this + 24) && v4 )
      (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v4 + 60))(v4, v2, v35);
    if ( v3 && v3 == *(_DWORD *)(this + 5484) )
    {
      if ( *(float *)(this + 212) + *(float *)(this + 208) <= *(float *)(this + 204) )
        goto LABEL_21;
      v6 = *(float *)(this + 192) + *(float *)(this + 204);
    }
    else
    {
      v6 = *(float *)(this + 204) - (*(float *)(this + 192) + *(float *)(this + 192));
      *(float *)(this + 204) = v6;
      if ( v6 < 0.0 )
        v6 = 0.0;
    }
    *(float *)(this + 204) = v6;
LABEL_21:
    if ( *(_DWORD *)(this + 116) == 1 && *(_DWORD *)(this + 5484) )
      Setter(*(_DWORD *)(this + 5484));
    v7 = *(_DWORD *)(this + 5484);
    if ( v7 )
    {
      switch ( *(_DWORD *)(this + 116) )
      {
        case 1:
        case 2:
          if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 140))(v7) )
          {
            v10 = UIStringAccessor(*(_DWORD **)(this + 5484));
            v11 = sub_497E80(v10);
            if ( v11 )
              RendererAlphaBlendSetter(v11);
          }
          if ( *(_DWORD *)(this + 116) == 2 )
            goto LABEL_30;
          break;
        case 3:
          if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 144))(v7) )
          {
            v17 = UIStringAccessor_6260(*(_DWORD **)(this + 5484));
            v18 = sub_497E80(v17);
            if ( v18 )
              RendererAlphaBlendSetter(v18);
          }
          if ( *(float *)(this + 196) > 0.2 )
          {
            v19 = ObjectSearchWithDoubleIteration((_DWORD *)this);
            if ( v19 )
            {
              if ( *(_DWORD *)(this + 5472) )
              {
                v20 = *(char **)(this + 5464);
                if ( !v20 )
                  v20 = byte_5EA438;
                if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, char *))(*v19 + 128))(v19, v20) )
                {
                  v21 = *(char **)(this + 5464);
                  if ( !v21 )
                    v21 = byte_5EA438;
                  (*(void (__thiscall **)(_DWORD *, char *, _DWORD, _DWORD))(*v19 + 132))(
                    v19,
                    v21,
                    *(_DWORD *)(this + 5472),
                    *(_DWORD *)(this + 5476));
                }
              }
            }
          }
          goto LABEL_48;
        case 4:
          v22 = *(_DWORD *)(this + 24);
          if ( v4 != v22 )
            (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v22 + 56))(v22, v2, v35);
          v23 = *(_DWORD *)(this + 5484);
          if ( v3 == v23 || (*(int (__thiscall **)(int))(*(_DWORD *)v23 + 72))(v23) )
            break;
          v24 = UIStringAccessor_6280(*(_DWORD **)(this + 5484));
LABEL_70:
          v25 = sub_497E80(v24);
          if ( v25 )
            RendererAlphaBlendSetter(v25);
          break;
        case 5:
        case 8:
          if ( *(float *)(this + 196) == 0.0 )
            (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 80))(v7);
          (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(this + 5484) + 148))(*(_DWORD *)(this + 5484));
          v24 = UIStringAccessor_62a0(*(_DWORD **)(this + 5484));
          goto LABEL_70;
        case 6:
          if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 96))(v7) )
          {
            v8 = UIStringAccessor(*(_DWORD **)(this + 5484));
            v9 = sub_497E80(v8);
            if ( v9 )
              RendererAlphaBlendSetter(v9);
          }
          if ( *(_DWORD *)(this + 116) == 2 )
LABEL_30:
            (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(this + 5484) + 92))(*(_DWORD *)(this + 5484));
          break;
        case 7:
          if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 100))(v7) )
          {
            v12 = UIStringAccessor_6260(*(_DWORD **)(this + 5484));
            v13 = sub_497E80(v12);
            if ( v13 )
              RendererAlphaBlendSetter(v13);
          }
          if ( *(float *)(this + 196) > 0.2 )
          {
            v14 = ObjectSearchWithDoubleIteration((_DWORD *)this);
            if ( v14 )
            {
              if ( *(_DWORD *)(this + 5472) )
              {
                v15 = *(char **)(this + 5464);
                if ( !v15 )
                  v15 = byte_5EA438;
                if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, char *))(*v14 + 128))(v14, v15) )
                {
                  v16 = *(char **)(this + 5464);
                  if ( !v16 )
                    v16 = byte_5EA438;
                  (*(void (__thiscall **)(_DWORD *, char *, _DWORD, _DWORD))(*v14 + 132))(
                    v14,
                    v16,
                    *(_DWORD *)(this + 5472),
                    *(_DWORD *)(this + 5476));
                }
              }
            }
          }
LABEL_48:
          RenderStateReset(this);
          break;
        case 0xC:
          (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 120))(v7);
          break;
        case 0xD:
          (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 124))(v7);
          break;
        default:
          break;
      }
    }
    *(_DWORD *)(this + 5528) = 0;
    if ( dword_7CB218 > 0 )
    {
      do
      {
        *(_WORD *)(this + 2 * *(_DWORD *)(this + 5528) + 5532) = word_7CB21C[*(_DWORD *)(this + 5528)];
        v26 = *(_DWORD *)(this + 5528) + 1;
        *(_DWORD *)(this + 5528) = v26;
      }
      while ( v26 < dword_7CB218 );
    }
    v27 = *(_DWORD *)(this + 32);
    LOBYTE(v35) = 0;
    if ( v27 && *(int *)(this + 5528) > 0 )
      LOBYTE(v35) = (*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v27 + 88))(
                      v27,
                      this + 5532,
                      *(_DWORD *)(this + 5528));
    UIClickEventDispatch((_DWORD *)this, *(_DWORD *)(this + 5528), this + 5532, v35);
    if ( dword_5CC9E8 == 5 )
      sub_496880((_DWORD *)this);
    if ( *(_DWORD *)(this + 116) == 5 )
      *(float *)(this + 196) = *(float *)(this + 192) + *(float *)(this + 196);
    else
      *(_DWORD *)(this + 196) = 0;
    FPSOverlayDraw(this);
    v28 = *(_DWORD *)(this + 92);
    v29 = *(_DWORD *)(this + 96);
    *(_DWORD *)(this + 120) = *(_DWORD *)(this + 88);
    v30 = *(_DWORD *)(this + 100);
    *(_DWORD *)(this + 124) = v28;
    v31 = *(_DWORD *)(this + 104);
    *(_DWORD *)(this + 128) = v29;
    v32 = *(_DWORD *)(this + 108);
    *(_DWORD *)(this + 132) = v30;
    v33 = *(_DWORD *)(this + 116);
    *(_DWORD *)(this + 136) = v31;
    *(_DWORD *)(this + 140) = v32;
    *(_DWORD *)(this + 148) = v33;
  }
  return 0;
}

