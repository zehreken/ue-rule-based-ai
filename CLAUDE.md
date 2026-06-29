# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A **Unreal Engine 5.7** project (`UERuleBasedAI.uproject`, `EngineAssociation: "5.7"`). At present it is a near-empty starter: **Blueprint-only** — there is no `Source/` directory and no C++ modules. The only meaningful content asset is the level `Content/UERuleBasedAI/L_Main.umap`. The name suggests the intended work is a rule-based AI system, but no such systems exist in the repo yet.

## Working in this project

- **Editing happens in the Unreal Editor**, not in text files. Blueprints, levels, and most assets are binary `.uasset`/`.umap` files under `Content/` and cannot be meaningfully read or hand-edited as text. To make gameplay/AI changes, the work is done in-editor.
- **No build/test/lint commands** apply while this is Blueprint-only — there is no project code to compile. If C++ is later added (a `Source/` folder with `*.Build.cs` / `*.Target.cs` and a module in `.uproject`), it is built via Unreal Build Tool / by generating the Visual Studio solution from the `.uproject` and building, or via the editor's "Live Coding".
- **Opening the project:** launch `UERuleBasedAI.uproject` with UE 5.7. `GameDefaultMap` is currently `/Engine/Maps/Templates/OpenWorld` (Config/DefaultEngine.ini), not `L_Main` — change this if `L_Main` should be the startup map.

## Key config facts (Config/DefaultEngine.ini)

Rendering is configured for a modern high-end setup; preserve these unless intentionally changing them:
- **Substrate** material system enabled (`r.Substrate=True`).
- **Ray tracing** enabled (`r.RayTracing=True`), including ray tracing proxies.
- **Lumen** GI/reflections (`r.DynamicGlobalIlluminationMethod=1`, `r.ReflectionMethod=1`), Virtual Shadow Maps, and static lighting disabled (`r.AllowStaticLighting=False`) — this is a fully dynamic-lighting project.
- RHI is **DirectX 12 / SM6** (`DefaultGraphicsRHI_DX12`).

## Plugins

Only `ModelingToolsEditorMode` is enabled, and only for the `Editor` target (Config + `.uproject`).

## Source control note

`DerivedDataCache/`, `Intermediate/`, and `Saved/` are generated/cache directories and should not be treated as source. Only `Config/`, `Content/`, and `UERuleBasedAI.uproject` are authored project files.
