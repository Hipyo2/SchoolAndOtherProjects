defmodule Cs491Hm2Web.PageController do
  use Cs491Hm2Web, :controller

  def index(conn, _params) do
    render(conn, "index.html")
  end
end
