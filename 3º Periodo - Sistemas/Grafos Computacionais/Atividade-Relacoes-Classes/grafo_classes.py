import networkx as nx
import matplotlib.pyplot as plt

# 1. Instancia um Grafo Direcionado
G = nx.DiGraph()

# 2. Definição das relações
relacoes = [
    ("BrowserList", "Browser", "Composição"),
    ("Browser", "TabStripModel", "Composição"),
    ("Browser", "BrowserWindow", "Composição"),
    ("TabStripModel", "WebContents", "Composição"),
    ("WebContentsImpl", "RenderFrameHostManager", "Composição"),
    ("RenderFrameHostManager", "RenderFrameHost", "Composição"),
    ("RenderFrameHostImpl", "RenderProcessHost", "Associação"),
    ("BrowserView", "BrowserWindow", "Herança"),
    ("Browser", "WebContentsDelegate", "Herança"),
    ("WebContentsImpl", "WebContents", "Herança"), 
    ("RenderFrameHostImpl", "RenderFrameHost", "Herança")
]

for origem, destino, tipo in relacoes:
    cor = "#2196F3" if tipo in ["Composição", "Associação"] else "#F44336"
    G.add_edge(origem, destino, relation=tipo, color=cor)

# 3. Categorização dos nós para divisão visual
render_nodes = ["WebContentsImpl", "RenderFrameHostManager", "RenderFrameHost", "RenderFrameHostImpl", "RenderProcessHost"]

# 4. Posicionamento Estratégico ESPAÇADO
# Coordenadas ampliadas (multiplicadas) para aumentar a distância entre os nós
pos = {
    # PARTE 1: Renderização (Mais afastado para a esquerda e distribuído na vertical)
    "WebContentsImpl": (-3.0, 12.5),
    "RenderFrameHostManager": (-3.0, 6),
    "RenderFrameHost": (-5.0, 1.5),
    "RenderFrameHostImpl": (-1.0, 1.5),
    "RenderProcessHost": (-3.66, -1.5),
    
    # PARTE 2: Interfaces de Janela e Abas (Mais afastado para a direita e distribuído na vertical)
    "BrowserList": (3.5, 12.5),
    "Browser": (1.5, 10.3),
    "BrowserWindow": (7.0, 10.5),
    "BrowserView": (7.0, -0.5),
    "WebContentsDelegate": (5.0, 6),
    "TabStripModel": (3.0, 3.5),
    "WebContents": (3.0, -2.10),
}

# 5. Aumentamos o figsize para acomodar o maior espaçamento
fig, ax = plt.subplots(figsize=(16, 10))

# Atribui cores de fundo
node_colors = ["#D4EDDA" if node in render_nodes else "#FFF3CD" for node in G.nodes()]
edge_colors = [G[u][v]['color'] for u, v in G.edges()]
edge_labels = {(u, v): G[u][v]['relation'] for u, v in G.edges()}

# 6. Renderização
nx.draw_networkx_nodes(G, pos, ax=ax, node_size=4000, node_color=node_colors, edgecolors="#666666")
nx.draw_networkx_labels(G, pos, ax=ax, font_size=9, font_weight="bold", font_family="sans-serif")
nx.draw_networkx_edges(G, pos, ax=ax, edge_color=edge_colors, width=2.5, arrowsize=20, connectionstyle="arc3,rad=0.1")

# Adiciona os rótulos das arestas com um pouco mais de transparência no fundo para evitar blocos muito densos
nx.draw_networkx_edge_labels(
    G, pos, ax=ax, edge_labels=edge_labels, font_size=9, label_pos=0.5,
    bbox=dict(facecolor="white", edgecolor="none", alpha=0.9, pad=3)
)

# Adiciona a Divisão Visual
ax.axvline(x=0, color='gray', linestyle='--', linewidth=2, alpha=0.5)

# Ajuste da posição dos títulos para acompanhar as novas coordenadas
ax.text(-5.2, 13, "Parte 1: Renderização", 
         fontsize=12, fontweight="bold", ha='center', va='center', 
         bbox=dict(facecolor='#D4EDDA', edgecolor='gray', boxstyle='round,pad=0.5'))

ax.text(1.4, 13, "Parte 2: Interfaces (UI)", 
         fontsize=12, fontweight="bold", ha='center', va='center', 
         bbox=dict(facecolor='#FFF3CD', edgecolor='gray', boxstyle='round,pad=0.5'))

# Configurações finais
ax.set_title("Arquitetura Core do Chromium: Separação de Domínios", fontsize=16, fontweight="bold", pad=1)
ax.axis("off")
plt.tight_layout()
plt.show()